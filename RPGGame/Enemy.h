#pragma once
#include <string>

class Enemy {
protected:
    double HealthPoints;
    double Damage;
    std::string name;
    std::string type;
    double xp; 

public:
    Enemy(const std::string& name, const std::string& type, double healthPoints, double damage,double xp)
        : name(name), type(type), HealthPoints(healthPoints), Damage(damage),xp(xp) {
    }

    virtual ~Enemy() {}

    // Getters
    double getHealthPoints() const { return HealthPoints; }
    double getDamage() const { return Damage; }
    const std::string& getName() const { return name; }
    const std::string& getType() const { return type; }
	double  getXP() const { return xp; }
    // Setters
    void setHealthPoints(double hp) { HealthPoints = hp; }
    void setDamage(double dmg) { Damage = dmg; }
    void setName(const std::string& n) { name = n; }
    void setType(const std::string& t) { type = t; }

    // Abstract methods
    virtual void dialogue(const std::string& text) const = 0;
    virtual double heavyAttack(Enemy& enemy) = 0;
    virtual double lightAttack(Enemy& enemy) = 0;
    virtual double specialAttack(Enemy& enemy) = 0;
    virtual void heal(int amout) = 0;
};
