namespace FriendSpace
{
    class Box
    {
    private:
        int height;
        int width;

    public:
        void setHeight(int height);
        void setWidth(int width);
        friend void printBox(Box &box);
    };

    void printBox(Box &box);
}
