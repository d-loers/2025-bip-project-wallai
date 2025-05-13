import cv2
from ultralytics import YOLO
import threading
import tkinter as tk
from PIL import Image, ImageTk

# Lade YOLOv8
model = YOLO("yolov8n.pt")

# Fenster zum Steuern
class App:
    def __init__(self, window):
        self.window = window
        self.window.title("YOLOv8 Dosen-Erkennung")
        self.stop = False

        # GUI-Elemente
        self.video_label = tk.Label(window)
        self.video_label.pack()

        self.stop_button = tk.Button(window, text="STOPP", command=self.stop_stream, bg="red", fg="white", font=("Arial", 14))
        self.stop_button.pack(pady=10)

        # Starte Video-Thread
        self.cap = cv2.VideoCapture(0)
        self.update_frame()

    def stop_stream(self):
        self.stop = True
        self.cap.release()
        self.window.destroy()

    def update_frame(self):
        if self.stop:
            return

        ret, frame = self.cap.read()
        if ret:
            results = model(frame)[0]
            for box in results.boxes:
                cls_id = int(box.cls[0])
                label = model.names[cls_id]
                conf = float(box.conf[0])

                if label in ["bottle", "cup", "can"] and conf > 0.5:
                    x1, y1, x2, y2 = map(int, box.xyxy[0])
                    cv2.rectangle(frame, (x1, y1), (x2, y2), (0,255,0), 2)
                    cv2.putText(frame, f"{label} {conf:.2f}", (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,255,0), 2)

            # Konvertiere zu Tk-kompatiblem Bild
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            img = Image.fromarray(rgb)
            imgtk = ImageTk.PhotoImage(image=img)
            self.video_label.imgtk = imgtk
            self.video_label.configure(image=imgtk)

        self.window.after(10, self.update_frame)

# Starte das Fenster
root = tk.Tk()
app = App(root)
root.mainloop()
