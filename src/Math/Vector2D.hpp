
#pragma once

#include <iostream>

template <class T>
class Vector2D {
  private :
    T x;
    T y;

  public:
    Vector2D() : x(0), y(0) {
    }

    Vector2D(T const& x, T const& y) : x(x), y(y) {
    }

    Vector2D(Vector2D const& u) : x(u.x), y(u.y) {
    }

    ~Vector2D() = default;

    void setX(T const& x) {
      this->x = x;
    }
    
    void setY(T const& y) {
      this->y = y;
    }
    
    T const& getX() const {
      return x;
    }

    T const& getY() const {
      return y;
    }

    template <class K>
    Vector2D<T>& operator+=(Vector2D<K> const& u) {
      x += static_cast <T> (u.x);
      y += static_cast <T> (u.y);
      return *this;
    }

    template <class K>
    Vector2D<T> operator+(Vector2D<K> const& u) const {
      Vector2D<T> tmp(*this);
      return tmp += u;
    }

    template <class K>
    Vector2D<T>& operator-=(Vector2D<K> const& u) {
      x -= static_cast <T> (u.x);
      y -= static_cast <T> (u.y);
      return *this;
    }

    template <class K>
    Vector2D<T> operator-(Vector2D<K> const& u) const {
      Vector2D<T> tmp(*this);
      return tmp -= u;
    }

    template <class K>
    bool operator==(Vector2D<K> const& u) {
      return x == u.x && y == u.y;
    }

    template <class K>
    bool operator!=(Vector2D<K> const& u) {
      return !(*this == u);
    }

    friend std::ostream& operator <<(std::ostream& stream, Vector2D<T> const& p) {
      stream << "(" << p.x << ", " << p.y << ")";
      return stream;
    }


};
