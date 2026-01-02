namespace targets {
    class Alien{
    public :
    int x_coordinate,y_coordinate;
    Alien(int x, int y)
    {
        x_coordinate = x;
        y_coordinate = y;
        
    }
    int get_health()
    {
        return health;
    }
    bool hit()
    {
        if(health>0)
        {
            health--;
        }
        return (health>0)? true:false;
    }
    bool is_alive()
    {
        return (get_health()>0);
    }
    bool teleport(int x_new, int y_new)
    {
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    }
    bool collision_detection(const Alien& alien2)
    {
        return ((x_coordinate == alien2.x_coordinate)&&(y_coordinate == alien2.y_coordinate))?true:false;
    }
    private:
    
    int health {3};
    };
    
}  // namespace targets
