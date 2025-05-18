from ultralytics import YOLO
import cv2
import os
import sys

# Загрузка модели
model = YOLO('best.pt')

# Путь к изображению
img_path = 'test.png'

# Предсказание
results = model.predict(img_path, imgsz=640, conf=0.5)

# Массив для найденных классов
detected_classes = []

# Обработка результатов
for result in results:
    # Сохраняем обработанное изображение
    img_with_boxes = result.plot()
    save_path = os.path.splitext(img_path)[0] + '_pred.png'
    cv2.imwrite(save_path, img_with_boxes)

    # Получаем имена классов
    for box in result.boxes:
        class_id = int(box.cls)
        class_name = model.names[class_id]
        detected_classes.append(class_name)

# Проверка на наличие опасных предметов
if 'Gun' in detected_classes or 'Knife' in detected_classes:
    sys.exit(1)
else:
    sys.exit(0)
