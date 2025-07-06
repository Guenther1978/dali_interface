///@file

struct Line() {
  *struct Point;
};

struct Pin() {
};

struct Point() {
  uint8_t x;
  uint8_t y;
};

struct Rectangle() {
};

struct Windows() {
  struct Rectangle;w
};

struct SerialInterface() {
  struct Window;
};
