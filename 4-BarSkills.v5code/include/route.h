

class Route {

  private:
    int driveTarget = 0;

  protected:
    int drivePos();
    bool isDriving();
  
  public:
    virtual void run();
};