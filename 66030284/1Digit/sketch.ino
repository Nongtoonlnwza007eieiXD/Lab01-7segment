// กำหนด GPIO ที่ต่อกับ segment แต่ละตัว
const int segmentPins[7] = {19, 18, 5, 17, 16, 4, 0}; // a, b, c, d, e, f, g

// กำหนดรูปแบบ segment สำหรับเลข 0-9 (0 = ปิด, 1 = เปิด)
const byte digitPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int digit = 0; digit <= 9; digit++) {
    // เปิด segment ตาม pattern
    for (int seg = 0; seg < 7; seg++) {
      digitalWrite(segmentPins[seg], digitPatterns[digit][seg]);
    }
    delay(1000); // แสดงแต่ละเลข 1 วินาที
  }
}



