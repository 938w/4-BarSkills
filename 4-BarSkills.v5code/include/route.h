

class Route {

  private:
    

  protected:
    int drivePos();
    bool isDriving();
    int _driveTarget = 0;
  
  public:
    virtual void run();
};