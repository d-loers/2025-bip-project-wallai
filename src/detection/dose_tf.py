import tensorflow as tf
import tensorflow_hub as hub
import numpy as np
import cv2

# Lade das Modell von TensorFlow Hub
model = hub.load("https://tfhub.dev/tensorflow/ssd_mobilenet_v2/2")

# COCO-Klassenlabels (Index = Klassen-ID)
labels = {
    1: 'person', 44: 'bottle', 47: 'cup', 53: 'apple', 62: 'chair', 67: 'cell phone',
    72: 'tv', 77: 'teddy bear', 84: 'book', 86: 'vase'
    # ... (du kannst die vollständige COCO-Klassenliste einfügen)
}

# Starte Kamera
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    img = cv2.resize(frame, (320, 320))
    rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    rgb_tensor = tf.convert_to_tensor(rgb, dtype=tf.uint8)
    rgb_tensor = tf.expand_dims(rgb_tensor, 0)

    detector_output = model(rgb_tensor)

    boxes = detector_output['detection_boxes'][0].numpy()
    class_ids = detector_output['detection_classes'][0].numpy().astype(np.int32)
    scores = detector_output['detection_scores'][0].numpy()

    h, w, _ = frame.shape

    for i in range(len(scores)):
        if scores[i] > 0.5:
            class_id = class_ids[i]
            label = labels.get(class_id, 'Objekt')
            if label in ['bottle', 'cup']:  # <- Dosenähnliche Objekte
                box = boxes[i]
                y1, x1, y2, x2 = box
                (x1, y1, x2, y2) = (int(x1 * w), int(y1 * h), int(x2 * w), int(y2 * h))

                cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.putText(frame, label, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

    cv2.imshow("TensorFlow Dose-Erkennung", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
