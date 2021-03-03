//
// Created by kosty on 02.03.2021.
//

#ifndef MAIN_CPP_SPELLS_H
#define MAIN_CPP_SPELLS_H
#include <iostream>
using namespace std;
class Spells {

protected:
    string Name; // Название
    string Stih; // Стихия заклинания (Всего 4 - Земля, Огонь, Вода, Воздух).
    string Type; // Тип (дамажный, антимагический, усиляющий, разум).
    string Distance; // Дистанция заклинания (Один/ауе/все персонажи).
    string Duration; // Длительность заклинания
    string Level; // Уровень заклинания.
    string Cost; // Цена в маны
public:
    Spells *spell [16];
    // (1 - дамаг, 2 - Разум, 3 - баф/дебаф, 4 -  магия/антимагия)
    // Огненные *Fireball(фаерболл), *Blind(Слепота), *Curse(Проклятие), *Fireshield(Огненный щит);
    // Водные *Icearrow(ледянная стрела), *Clone(Клон), *Wikness(Слабость), *Waterdefence(Защита от магии воды);
    // Земля *Boom(Взрыв), *UndeadDead(Упокоить мертвецов), *StoneSkin(Каменная кожа), *DirtDefence(Защита от магии земли);
    // Воздух. *Сhainzipper(Цепная молния), *Accuracy(Точность), *Lucky(Удача), *Dimensiondoor(Дверь измерений)

};
class DSpell : public Spells
{
private: int Damage; // Дамаг заклинания
public:
    void SetDSpell(string name, string stih, string type, string distance, string level, string cost, string duration, int damage){
        Name = name;
        Stih = stih;
        Type = "D";
        Distance = distance;
        Level = level;
        Cost = cost;
        Duration = duration;
        Damage = damage;
    }
   DSpell Fireball(), Icearrow(), boom(), Chainzipper();
}; // Дамажные заклинания
class SSpell : public Spells
{
private: string Effect; // Эффект заклинания
public:
    void SetSpell(string name, string stih, string type, string distance, string level, string cost, string duration, string effect)
    {
        Name = name;
        Stih = stih;
        Type = type;
        Distance = distance;
        Level = level;
        Cost = cost;
        Duration = duration;
        Effect = effect;
    }
    SSpell Clone(), Wikness(), Waterdefence(), Blind(), Curse(), Fireshield(), UndeadDead(), StoneSkin(), DirtDefence(), Accuracy(), Lucky(), Dimensiondoor();
};







#endif //MAIN_CPP_SPELLS_H
