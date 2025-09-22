from ultralytics import YOLO
import cv2
import math 
import serial
import time
model = YOLO("best (3).pt")
arduino_port = 'COM7'
baud_rate = 9600 

ser = serial.Serial(arduino_port, baud_rate, timeout=1)
time.sleep(2)
start_time = time.time()
thres_time=0
lane=1
emr_flag=0

cap1 = cv2.VideoCapture(r"C:\Users\nisha\OneDrive\Documents\projectt\final videos\video_3(pashu).mp4")
cap2 = cv2.VideoCapture(r"C:\Users\nisha\Downloads\WhatsApp Video 2024-04-04 at 10.44.24 PM.mp4")
cap3 = cv2.VideoCapture(r"C:\Users\nisha\Downloads\Chakka Frame extract (1).mp4")
cap4 = cv2.VideoCapture(r"C:\Users\nisha\OneDrive\Documents\projectt\final videos\video_2(gb).mp4")
while True:
    count1=0
    count2=0
    count3=0
    count4=0
    
    success1, img1 = cap1.read()
    success2, img2 = cap2.read()
    success3, img3 = cap3.read()
    success4, img4 = cap4.read()
    if not success1:
        break
    if not success2:
        img2=img1
    if not success3:
        break
    if not success4:
        break
    results1 = model(img1, stream=True, verbose=False)
    for r in results1:
        boxes = r.boxes
        for box in boxes:
            confidence = math.ceil((box.conf[0]*100))/100
            if confidence>0.3:
                x1, y1, x2, y2 = box.xyxy[0]
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
                cls = int(box.cls[0])
                org = [10, 40]
                font = cv2.FONT_HERSHEY_SIMPLEX
                fontScale = 1
                color = (0, 255, 0)
                thickness = 2
                count1+=1
                color = (0, 255, 0) 
                cv2.rectangle(img1, (x1, y1), (x2, y2), color, 1)
                if cls==0:
                    emr_flag=1
    
    results2 = model(img2, stream=True, verbose=False)
    for r in results2:
        boxes = r.boxes
        for box in boxes:
            confidence = math.ceil((box.conf[0]*100))/100
            if confidence>0.3:
                x1, y1, x2, y2 = box.xyxy[0]
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
                cls = int(box.cls[0])
                org = [10, 40]
                font = cv2.FONT_HERSHEY_SIMPLEX
                fontScale = 1
                color = (0, 255, 0)
                thickness = 2
                count2+=1
                color = (0, 255, 0)
                cv2.rectangle(img2, (x1, y1), (x2, y2), color, 1)
                if cls==0:
                    emr_flag=2
    
    results3 = model(img3, stream=True, verbose=False)
    for r in results3:
        boxes = r.boxes
        for box in boxes:
            confidence = math.ceil((box.conf[0]*100))/100
            if confidence>0.3:
                x1, y1, x2, y2 = box.xyxy[0]
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
                cls = int(box.cls[0])
                org = [10, 40]
                font = cv2.FONT_HERSHEY_SIMPLEX
                fontScale = 1
                color = (0, 255, 0)
                thickness = 2
                count3+=1
                color = (0, 255, 0)
                cv2.rectangle(img3, (x1, y1), (x2, y2), color, 1)
                if cls==0:
                    emr_flag=3
    
    results4 = model(img4, stream=True, verbose=False)
    for r in results4:
        boxes = r.boxes
        for box in boxes:
            confidence = math.ceil((box.conf[0]*100))/100
            if confidence>0.3:
                x1, y1, x2, y2 = box.xyxy[0]
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
                cls = int(box.cls[0])
                org = [10, 40]
                font = cv2.FONT_HERSHEY_SIMPLEX
                fontScale = 1
                color = (0, 255, 0)
                thickness = 2
                count4+=1
                color = (0, 255, 0)
                cv2.rectangle(img4, (x1, y1), (x2, y2), color, 1)
                if cls==0:
                    emr_flag=4
                

    cv2.putText(img1, "Lane 1 count: "+str(count1), org, font, fontScale, (255, 0, 0), thickness)
    cv2.putText(img2, "Lane 2 count: "+str(count2), org, font, fontScale, (255, 0, 0), thickness)
    cv2.putText(img3, "Lane 3 count: "+str(count3), org, font, fontScale, (255, 0, 0), thickness)
    cv2.putText(img4, "Lane 4 count: "+str(count4), org, font, fontScale, (255, 0, 0), thickness)
    img1=cv2.resize(img1,(640, 360),interpolation = cv2.INTER_LINEAR)
    img2=cv2.resize(img2,(640, 360),interpolation = cv2.INTER_LINEAR)
    img3=cv2.resize(img3,(640, 360),interpolation = cv2.INTER_LINEAR)
    img4=cv2.resize(img4,(640, 360),interpolation = cv2.INTER_LINEAR)
    im_h_1 = cv2.hconcat([img1, img2])
    im_h_2 = cv2.hconcat([img3, img4]) 
    imz=cv2.vconcat([im_h_1, im_h_2]) 
    cv2.imshow('Result1', imz)

    if emr_flag!=0:
        emr_lane=4+emr_flag
        data_to_send = str(emr_lane)
        d="5"
        ser.write(d.encode())
        start_time = time.time()
        emr_flag=0
        thres_time=5
        
    else:
        elapsed_time = time.time() - start_time
        if elapsed_time >= thres_time:
            if lane==1:
                if count1>20:
                    thres_time=10
                else:
                    thres_time=5
            elif lane==2:
                if count2>20:
                    thres_time=10
                else:
                    thres_time=5
            elif lane==3:
                if count3>20:
                    thres_time=10
                else:
                    thres_time=5
            elif lane==4:
                if count4>20:
                    thres_time=10
                else:
                    thres_time=5
                    
            data_to_send = str(lane)
            ser.write(data_to_send.encode())
            start_time = time.time()
            lane+=1
        if lane>4:
            lane=1
              
    if cv2.waitKey(1) == ord('q'):
        break
cap1.release()
cap2.release()
cap3.release()
cap4.release()
cv2.destroyAllWindows()
data_to_send = "6"
ser.write(data_to_send.encode())
