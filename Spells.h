//
// Created by kosty on 02.03.2021.
//

#ifndef MAIN_CPP_SPELLS_H
#define MAIN_CPP_SPELLS_H
#include <iostream>
using namespace std;
class Spells {

protected:
    int Name; // Название
    string Stih; // Стихия заклинания (Всего 4 - Земля, Огонь, Вода, Воздух).
    string Type; // Тип (дамажный, антимагический, усиляющий, разум).
    string Distance; // Дистанция заклинания (Один/ауе/все персонажи).
    string Duration; // Длительность заклинания
    string Level; // Уровень заклинания.
    string Cost; // Цена в маны
public:
    // (1 - дамаг, 2 - Разум, 3 - баф/дебаф, 4 -  магия/антимагия)
    // Огненные *Fireball(фаерболл), *Blind(Слепота), *Curse(Проклятие), *Fireshield(Огненный щит);
    // Водные *Icearrow(ледянная стрела), *Clone(Клон), *Wikness(Слабость), *Waterdefence(Защита от магии воды);
    // Земля *Boom(Взрыв), *UndeadDead(Упокоить мертвецов), *StoneSkin(Каменная кожа), *DirtDefence(Защита от магии земли);
    // Воздух. *Сhainzipper(Цепная молния), *Accuracy(Точность), *Lucky(Удача), *Dimensiondoor(Дверь измерений)
     static Spells Clone, Weakness, Waterdefence, Blind, Curse, Fireshield, UndeadDead, StoneSkin, DirtDefence, Accuracy, Lucky, Dimensiondoor, Fireball, Icearrow, boom, Chainzipper;

    void SetSpell(int Name, string Stih, string Type, string Distance, string Duration, string Level, string Cost)
    {
        this->Name = Name;
        this->Stih = Stih;
        this->Type = Type;
        this->Distance = Distance;
        this->Duration = Duration;
        this->Level = Level;
        this->Cost = Cost;
    }
void CastSpell(int name, Spells a)
{
    switch (Name) {

    }
}
   enum spellsname
   {
        NClone,
        NWeakness,
        NWaterdefence,
        NBlind,
        NCurse,
        NFireshield,
        NUndeadDead,
        NStoneSkin,
        NDirtDefence,
        NAccuracy,
        NLucky,
        NDimensiondoor,
        NFireball,
        NIcearrow,
        Nboom,
        NChainzipper
   };


};








#endif //MAIN_CPP_SPELLS_H
