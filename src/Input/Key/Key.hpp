#pragma once

class Key {
  private:
    bool active;
    bool flip;

  public:
    Key();
    ~Key() = default;
    void setActive(bool a);
    bool const& isActive() const ;
    void keyUp();
    void keyDown();
    void isFlip();

};
