// template <typename T> // during the object creation we need to specify the type T here.
template <typename T, typename V> // during the object creation we need to specify the type T here.
class Pair{
  T x;
  V y;

  public:
    void setX(T x){
      this->x = x;
    }

    T getX(){
      return x;
    }

    void setY(V y){
      this->y = y;
    }

    V getY(){
      return y;
    }

};