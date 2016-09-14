#pragma once
class Laser_Bolt : public Entity{
public:
    Laser_Bolt(Game* g, Location l, vec2 d, float s);
    ~Laser_Bolt();
};