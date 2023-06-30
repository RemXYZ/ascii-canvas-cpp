class Canvas {
public:
    virtual ~Canvas() = default;
    virtual void setDimension(int height, int width) = 0;
    virtual void draw() = 0;
protected:
    int height;
    int width;
};
