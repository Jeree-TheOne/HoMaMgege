//
// Created by kosty on 09.03.2021.
//

#ifndef MAIN_CPP_ENTERPRISES_H
#define MAIN_CPP_ENTERPRISES_H
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "Randomize.h"
#include "Equipment.h"
#include "Hero.h"
#include "Format.h"
#include "Units.h"

class Enterprise
{
protected:
    int type;
    vector<int> eventhandler;
public:
    Enterprise()
    {

    }
    void SetType(int type)
    {
        this->type = type;
    }
};
class Tavern : public Enterprise
{
private:
    int Price;
    bool roomExists;
public:
    Tavern()
    {
        roomExists = true;
        int j = 0;
        switch(this->type)
                {
                    case 0: j= 20; break;
                    case 1: j= 15; break;
                    case 2: j= 15; break;
                    case 3: j= 10; break;
                    case 4: j= 10; break;
                    case 5: j= 5; break;
                    case 6: j= 0; break;
                    case 7: j= 2; break;
                };
        switch(this->type)
                {
           case 0: this->Price = 50; break;
           case 1: this->Price = 45; break;
           case 2: this->Price = 45; break;
           case 3: this->Price = 25; break;
           case 4: this->Price = 15; break;
           case 5: this->Price = 15; break;
           case 6: this->Price = 10; break;
           case 7: this->Price = 5; break;
                };
        for(int i = 0; i<j; i++)
            this->eventhandler.push_back(0); // Нет свободной комнаты(невозможно хиллиться, пропадает кнопка снять комнату)
        for(int i = 0 ; i<35-j; i++)
            this->eventhandler.push_back(1); // Ничего не произошло(комната снята)
        for(int i = 0; i<35-5-j; i++)
            this->eventhandler.push_back(2); // Началась пиздилка(победа - +200 голды и бесплатная комната, поражение - минус 300 золота и закрытая таверна)

    }
    void EnterTheTavern(Hero hero)
    {
        int j;
        cout << "Вы подходите ко стойке хозяина таверны и решаете.. \n";
        while(j == 1 && roomExists == true) {
            int i = 0;
            if (roomExists == true)
                cout << i++ << ") Снять комнату. \n";
            cout << i++ << ") Уйти. \n";
            cin >> j;
            if (j == 1 && roomExists == true)
                roomExists = ArendRoom(hero);
        }
        cout << "\n";
        cout << "\n";
    }
    bool ArendRoom(Hero hero)
    {
        int j = this->eventhandler[Randomize::GetRand(0, this->eventhandler.size()-1)];
                switch (j)
                {
                    case 0:
                        {
                            cout<< "Вы окликаете хозяина таверны и к вам поворачивается упитанный мужчина за стойкой харчевни \n";
                            cout << "- К вашему сожалению свободных комнат нет, приходите позже или... \n";
                            cout << "Под сальными усами мужика загорелись коричневые глаза, кажется вы понимаете что к чему.\n";
                            nehvatajet:
                            cout << "1) Оказать любезность в размере " << this->Price*2+this->Price/5 << " золотых \n";
                            cout << "2) Намекнуть о серьезности своих намереваний "<< this->Price*2 << " золотыми \n";
                            cout << "3) Попытаться разворошить эту шаражкину контору!";
                            cout << "4) Пожав плечами, отойти от стойки";
                            int Gold = hero.GetGold();
                            cin >> j;
                            switch (j)
                            {
                                case 1:
                                    {
                                        if (Gold < (this->Price*2+this->Price/5))
                                        {
                                            cout << "У вас недостотаточно золота для любезностей! \n";
                                            goto nehvatajet;
                                        }
                                        else if (this->type > 1)
                                        {
                                            cout   << "- Вот черт, забылся старик уже, что скоро у нас освободится одна комната - жадно выхватив купюру из-под прилавка, он открывает ключом люк в погреб \n";
                                            cout << "Спускаясь за ним в заприлавочное подземелье, вы становитесь невользным слушателем, о том, как в далеком прошлом этот подземный Gym был покинут всеми Masters, кроме одного \n";
                                            cout << "Выслушав истории мужика о его leather gloves, вы ложитесь на stinky матрац, где проведете всю ночь \n";
                                            // TODO сделать восстановление здоровья юнитов
                                            Sleep(1000);
                                            hero.SetMana(hero.GetMAXmana());
                                            cout << "\n";
                                            cout << "Вы хорошо выспались и отдохнули";
                                            cout << "\n";
                                        }
                                        else
                                        {
                                            int j = Randomize::GetRand(0,10);
                                            if (j<5)
                                            {
                                                cout   << " FUCKING SLAVE! - стукнул хозяина заведения по столу, - Ты за кого меня принимаешь? За jabhronie?\n";
                                                cout << "Пошёл быстро нахер отседова, чтобы глаза мои больше твоей нахальской рожи не видывали! \n";
                                                cout << "Вам ничего не остается, как отойти от стойки. \n";
                                                return false;
                                            }
                                        }
                                    }
                                case 2:
                                {
                                    if (Gold < (this->Price*2))
                                    {
                                        cout << "У вас недостотаточно золота для намёков! \n";
                                        goto nehvatajet;
                                    }
                                    else if (this->type >= 3)
                                    {
                                       cout  << "Потеребя усы, он случайно находит ключ и называет вам номер комнаты";
                                        // TODO сделать восстановление здоровья юнитов
                                        Sleep(1000);
                                        hero.SetMana(hero.GetMAXmana());
                                        cout << "\n";
                                        cout << "Вы хорошо выспались и отдохнули";
                                        cout << "\n";
                                        return true;
                                    }
                                    else
                                    {
                                        int j = Randomize::GetRand(0,20);
                                        if (j<=15)
                                        {
                                            cout   << " FUCKING SLAVE! - стукнул хозяина заведения по столу, - Ты за кого меня принимаешь? За jabhronie?\n";
                                            cout << "Пошёл быстро нахер отседова, чтобы глаза мои больше твоей нахальской рожи не видывали!";
                                            cout << "Вам ничего не остается, как отойти от стойки.";
                                            return false;
                                        }
                                    }
                                }
                                case 3:
                                {
                                    if (this->type >3) {
                                        if (hero.GetIntellect() > 5) {
                                            cout
                                                    << "Вы молниеносно схватываете на ходу о том, что таверне не светит ничего хорошего в близжайшем будущем и трактирщик это понимает \n";
                                            cout
                                                    << "- Я прибыл из центрального DungGym-надзора, предъявите ваши leather-gloves, оформим протокол о ненадлежайшем состоянии этой лачуги - С уверенностью в груди заявили вы, не выдав себя \n";
                                            cout
                                                    << "Засуетившись, трактирщик внезапно находит ключ от свободной комнаты. Протянув вам конверт с ключом и чем-то звенящим, печальным выражением лица дал вам понять, что сожалеет и в скором времени исправится \n";
                                            // TODO сделать восстановление здоровья юнитов
                                            Sleep(1000);
                                            hero.SetMana(hero.GetMAXmana());
                                            cout << "\n";
                                            cout << "Вы хорошо выспались и отдохнули";
                                            cout << "\n";
                                            return true;
                                        } else {
                                            cout << "Ваши глаза не улавливают ни единой детали, вы решаете импровизировать \n";
                                            cout << "Эээ ну может проявите хоть чуточку милосердия к многодетной матери! - Вы сами в шоке от сказанного. \n";
                                            cout << "После десяти секунд молчания, вы решили больше не появляться в этом заведении \n";
                                            return false;
                                        }
                                    }
                                    else {
                                        if (hero.GetIntellect() > 10) {
                                            cout
                                                    << "Вы молниеносно схватываете на ходу о том, что здоровяк у дальней бочки в главном зале чем-то недоволен \n";
                                            cout
                                                    << "Подойдя к нему, вы затеяли светский разговор и поняли причину обиды такого робкого, но опасного мужчины - он потерял семью на недавней войне со Slaves\n";
                                            cout
                                                    << " Трактирщик с ярким Slavevskym акцентом слышит о чем вы говорите и, с дрожью в ногах, отдает вам ключ сугубо на одну ночь, пригрозив задушить вас во сне. \n";
                                            // TODO сделать восстановление здоровья юнитов
                                            hero.SetMana(hero.GetMAXmana());
                                            Sleep(1000);
                                            cout << "\n";
                                            cout << "Вы хорошо выспались и отдохнули";
                                            cout << "\n";
                                            return false;
                                        } else {
                                            cout
                                                    << "Ваши глаза не улавливают ни единой детали, вы решаете импровизировать \n";
                                            cout
                                                    << "Эээ ну может проявите хоть чуточку милосердия к многодетной матери! - Вы сами в шоке от сказанного. \n";
                                            cout
                                                    << "После десяти секунд молчания, вы решили больше не появляться в этом заведении \n";
                                            return false;
                                        }
                                    }
                                }
                                case 4: {
                                    return false;
                                }
                            }
                        }
                    case 1:
                        {
                            cout << "Окликнув трактирщика, вы узнаете, что комната будет стоить " << this->Price << " за одну ночь \n";
                            nehvatajetcase1:
                            cout << "1) Снять комнату";
                            cout << "2) Отойти от стойки таверны";
                            int h;
                            cin >> h;
                            if (h == 2)
                                return true;
                            else {
                                if (hero.GetGold()<this->Price)
                                {
                                    cout << "У вас нехватает золота на снятие комнаты \n";
                                    cout << "\n";
                                    goto nehvatajetcase1;
                                }
                                else {
                                    hero.SetGold(hero.GetGold()-this->Price);
                                    cout << "Вы успешно снимаете простую, но уютную комнату. Решивши, что ваш рабочий день окончен, вы крепко засыпаете до утра следущего дня \n";
                                    Sleep(1000);
                                    hero.SetMana(hero.GetMAXmana());
                                    cout << "\n";
                                    cout << "Вы хорошо выспались и отдохнули";
                                    cout << "\n";
                                    return true;
                                }
                            }
                        break;
                        }
                    case 2:
                        {
                            cout << "\n";
                            cout << "Вашу беседу с трактирщиком насчёт аренды комнаты прервал внезапно сломавшийся стул и крики. \n";
                            cout << "Лучше бы там просто кто-то упал, но нет, трактирщик дает вам понять, что пора прятаться за стойкой - выпившие не поделили, кто из них насоящий Boss of this INN \n";
                            cout << "Он просит вас что-то сделать с происходящим, вы решаете.. \n";
                            cout << "\n";
                            cout << "1) Показать этим слэйвам, кто тут Boss of this INN, пока они не разгромили тут все к чертям \n";
                            cout << "2) Выбежать из таверны, пока вам не надавали по самые Fat cocks \n" ;
                            int h = 0;
                            cin >> h;
                            if (h == 1)
                            {
                                int rand1 = Randomize::GetRand(0, hero.GetDamage());
                                int rand2 = Randomize::GetRand(5, hero.GetDamage()+(7-this->type));
                                if (rand1 > rand2)
                                {
                                    Sleep(1000);
                                    cout << " \n";
                                    cout << "Вы наносите удар за ударом по разным раскрасневшимся лицам до тех пор, пока не добиваете последнего. \n";
                                    cout << "Трактирщик благодарен вашей помощи и поощеряет ваши действия бесплатной комнатой на ночь, в которой вы находите 2000 золотых";
                                    hero.SetGold(hero.GetGold()+200);
                                    Sleep(1000);
                                    hero.SetMana(hero.GetMAXmana());
                                    cout << "\n";
                                    cout << "Вы хорошо выспались и отдохнули";
                                    cout << "\n";
                                }
                                else
                                {
                                    Sleep(1000);
                                    cout << "Один неверный шаг - вы падаете на сломанную под ногами бочку. \n";
                                    cout << "Вы просыпаетесь на следующий день в комнате трактирщика, без чести и 500 золотых в кармане \n";
                                    cout << "Встретив владельца таверны, вы понимаете, что в близжайшую неделю она будет закрыта, а значит вам будет негде отдохнуть \n";
                                    return false;
                                }
                            }
                            else
                            {
                                cout << "Вы трусливо бежите из-под прилавка тавернщика и решаете, что вам не следует больше сюда возвращаться \n";
                                return false;
                            }
                            break;
                        }
                }
    }
};
class Marketplace : public Enterprise
{
private:
    vector<string>Slots;
public:
    Marketplace()
    {
        int SlotsSize;
        switch(this->type)
                {
            case 0: SlotsSize = Randomize::GetRand(10,15); break;
            case 1: SlotsSize = Randomize::GetRand(8,13); break;
            case 2: SlotsSize = Randomize::GetRand(6,11); break;
            case 3: SlotsSize = Randomize::GetRand(6,8); break;
            case 4: SlotsSize = Randomize::GetRand(4,7); break;
            case 5: SlotsSize = Randomize::GetRand(3,6); break;
            case 6: SlotsSize = Randomize::GetRand(1,3); break;
            case 7: SlotsSize = 1;
                };
        Equipment eqipirovka;
        for (int i = 0; i<SlotsSize; i++)
        {
            eqipirovka.NewEquipment();
            this->Slots.push_back(eqipirovka.GetName()); // Слот Имени.
            this->Slots.push_back(eqipirovka.GetType()); // Слот Типа.
            this->Slots.push_back(eqipirovka.GetStats()); // Слот Статистики.*/
        }
    }
    void EnterTheMarketPlace(Hero hero)
    {
        cout << "Вы прибываете на рынок местного города, вы решаете..";
        centrmarket:
        cout << "\n";
        cout << "1) Просмотреть ассортимент \n";
        cout << "2) Уйти \n";
        cout << "\n";
        int h = 0;
        cin >> h;
        if (h == 1)
        {
            povtor:
            system("cls");
            int predmetiTORG = 0;
            cout << "У вас есть сейчас " << hero.GetGold() << "золотых с собой \n";
            cout << "Инвентарь торговца: \n";
            for (int i = 0; i<this->Slots.size(); i = i + 3)
            {
               cout << predmetiTORG++ << ") " << Slots[i] << "вида  " << Slots[i+1] << " " << Format::DeFormat(Slots[i+2]) << "\n";
               cout << "\n";
            }

            if(hero.Inventory.size()!=0)
                cout << "Ваш инвентарь: \n";
            int predmetiVASHI = 0;
            for (int i = 0; i<hero.Inventory.size(); i++)
            {
                cout << predmetiVASHI++ << ") " << hero.Inventory[i].GetName() << "вида  " << hero.Inventory[i].GetType() << " " << Format::DeFormat(hero.Inventory[i].GetStats()) << "\n";
                cout << "\n";
            }
            cout << "\n";

            cout << "Вы желаете.. \n 1) Купить предмет. \n 2) Продать предмет. \n 3) Вернуться на рыночную площадь \n";
            int DEJSTVIJE;
            if (DEJSTVIJE == 3)
                goto centrmarket;
            else if (DEJSTVIJE == 1)
            {
                cout << "Введите номер предмета продавца, который необходимо купить \n";
                int nomerpredmetaTORG;
                cin >> nomerpredmetaTORG;
                if (Format::FormatForBonusStats(Slots[nomerpredmetaTORG*3-1])[5]>hero.GetGold()) {
                    cout << "Вы не можете позволить себе приобретение этого предмета\n";
                    Sleep(1000);
                    goto povtor;
                }
                else
                {
                    hero.SetGold(hero.GetGold()-Format::FormatForBonusStats(Slots[nomerpredmetaTORG*3-1])[5]);
                Equipment equipment;
                equipment.AddEquipment(Slots[nomerpredmetaTORG*3-3],Slots[nomerpredmetaTORG*3-2], Slots[nomerpredmetaTORG*3-1]);
                hero.Inventory.push_back(equipment);
                    goto  povtor;
                }

            }
            else if (DEJSTVIJE == 2){
                cout << "Введите номер вашего, который необходимо продать \n";
                int nomerpredmetaTORG;
                cin >> nomerpredmetaTORG;
                this->Slots.push_back(hero.Inventory[nomerpredmetaTORG].GetName());
                this->Slots.push_back(hero.Inventory[nomerpredmetaTORG].GetType());
                this->Slots.push_back(hero.Inventory[nomerpredmetaTORG].GetStats());
                hero.Inventory.erase(hero.Inventory.begin() + nomerpredmetaTORG);
                hero.SetGold(hero.GetGold()+Format::FormatForBonusStats(hero.Inventory[nomerpredmetaTORG].GetStats())[5]);
                goto povtor;
            }

        }
    }
};
class Mercenary : public Enterprise // Покупка войнов
{
private:
    vector<Units>Slots;
public:
    Mercenary(vector<Units>Slots)
    {
        this->Slots = Slots;
    }
    void EnterTheMercenaryMarket(Hero hero)
    {
        povtorr:
        system("cls");
        cout << "Прогуливаясь по городу, вы замечаете палатки со флагами наемников - войнов, которые сражаются за вас, пока имеете золото \n";
        cout << "1) Направиться к шатёрам \n";
        cout << "2) Уйти \n";
        int h = 0;
        cin >> h;
        if (h == 1)
        {
            povtor:
            system("cls");
            cout << "У вас есть сейчас " << hero.GetGold() << "золотых с собой \n";
            cout << "Лагерь наёмников: \n";
            for (int i = 0; i<this->Slots.size(); i++)
            {
                cout << i << ") " << Slots[i].GetName() << " Расса:  " << Slots[i].GetRace() << " Броня: " << Slots[i].GetArmor() << " Аттака: " << Slots[i].GetDamage() << " Здоровье: " << Slots[i].GetHP() << " Максимальное колличество в одной клетке: " << Slots[i].GetMaxAmount() << " Цена: " << Slots[i].GetCost() <<"\n";
                cout << "\n";
            }
            cout << "\n";
            cout << "\n";
            cout << "1) Нанять челиксов \n";
            cout << "2) Вернуться в центр лагеря \n";
            int j;
            cin >> j;
            if (j == 2)
                goto povtorr;
            bool est = false;
            int x = 0;
            cout << "Введите номер юнита, которого необходимо нанять \n";
            int num;
            cin >> num;
            cout << "Введите колличество юнитов, которых необходимо нанять. \n";
            int kolvo;
            cin >> kolvo;
            for(x; x<hero.army.size(); x++) {
                if (hero.army[x].GetName() == "" || ((hero.army[x].GetName() == Slots[j-1].GetName()) && (hero.army[x].GetMaxAmount()<(hero.army[x].GetAmount()+kolvo)))) {
                    est = true;
                    break;
                }
            }
            if (j == 1 && est == false) {
                cout << "Воины бы с радостью к вам присоединились, однако вам нечем прокормить их \n";
                Sleep(5000);
                goto povtorr;
            }
            else
            {
                if (kolvo*Slots[num].GetCost()>hero.GetGold())
                {
                    cout << "У вас недостаточно золота! \n";
                    Sleep(3000);
                    goto povtor;
                }
                else if (kolvo+hero.army[x].GetAmount() > Slots[num].GetMaxAmount())
                {
                    cout << "Толпа не может поместиться в один обоз! Оформите покупки двумя разными чеками \n";
                    goto povtor;
                }
                else
                {
                    Slots[num].SetAmount(kolvo+hero.army[x].GetAmount());
                    hero.army[x] = Slots[num];
                    hero.SetGold(hero.GetGold()-kolvo*Slots[num].GetCost());
                    goto povtor;
                }
            }


        }
    }
};
class MagicTower : public Enterprise // Покупка заклинаний
{
private:
    vector<Spells>Slots;
public:
    MagicTower(vector<Spells>Slots)
    {
       this->Slots =Slots;
    }
   void EnterTheMagicTower(Hero hero)
    {
        nachalo:
        system("cls");
        cout << "Вы на цырлах пробираетесь в центр холла величавой башни магов \n";
        cout << "1) Подойти к стойке мейстеров \n";
        cout << "2) Уйти \n";
        int j = 0;
        cin >> j;
        if (j == 1)
        {
            povtor:
            system("cls");
            cout << "Вы потихоньку подходите к стойке - уполномоченное лицо, не взирая на ваше присутствие показывает на стойку слева \n";
            cout << "Подойдя к стойке слева, вы видите возмущенную женщину  'средних лет', которая высказывает непонимание зачем вас к ней направили и выдает талон в кабинет на 30-том этаже \n";
            cout << "Пройде 20 кругов бюрократического ада, перед вами наконец-то появляется консультант по продаже свитков заклинаний \n";
            cout << "Вы открываете прайс лист и видите в нём.. \n";
            cout << "Ваше золото: " << hero.GetGold() << "Ваша магическая сила: " << hero.GetMagicStrength() << "\n";
            for(int i = 0; i<Slots.size(); i++) {
                string name = Slots[i].GetSpell()[0];
                string stih = Slots[i].GetSpell()[1];
                if (stih == "Fire")
                    stih = "школы магии огня";
                else if (stih == "Water")
                    stih = "школы магии воды";
                else if (stih == "Earth")
                    stih = "школы магии земли";
                else if (stih == "Air")
                    stih = "школы магии воздуха";
                string type = Slots[i].GetSpell()[2];
                if (type == "Damage")
                    type = "урона";
                else if (type == "Mind")
                    type = "разума";
                else if (type == "Buff")
                    type = "поддержки";
                else if (type == "Magic")
                    type = "архимагического уровня";
                string damage = Slots[i].GetSpell()[3];
                string distance = Slots[i].GetSpell()[4];
                string duration = Slots[i].GetSpell()[5];
                string level = Slots[i].GetSpell()[6];
                string mcost = Slots[i].GetSpell()[7];
                string gcost = Slots[i].GetSpell()[8];
                cout << ++i << ") " << name << "  - заклинание " << type;
                if (damage!="0")
                    cout << "на" << damage << "урона";
                cout << " " << stih << " время действия - " << duration << " хода, распространяется на " << distance << " отр; Для покупки необходимо владеть хотя бы " << level << " уровнем магической силы, требует маны - " << mcost << " ед. Стоимость покупки - "<< gcost << "золотых монет \n";

            }
            cout << "Введите номер заклинания, которое необходимо купить или" << Slots.size() <<", чтобы покинуть мага-консультанта \n";
            n:
            cin >> j;
            if (j!= Slots.size())
            {
                if (hero.GetGold() < atoi(Slots[j - 1].GetSpell()[7].c_str()))
                {
                    cout << "Да вы не в состоянии считать! Вы не можете позволить приобритения данного заклинания \n";
                    goto n;
                }
                else if (hero.GetMagicStrength() < atoi(Slots[j - 1].GetSpell()[6].c_str()))
                {
                    cout << "Надев на вас обруч проверки силы магии, консультант заметил, что вам нехватает магической силы \n";
                    cout << "Приходите позже, когда достигните уровня покупки этого заклинания \n";
                    goto n;
                }
                else
                {
                    cout << "Проверив ваши знания с помощью магического обруча, продавец принимает ваш платеж и вручает вам свиток \n";
                    hero.MagicBook.push_back(Slots[j - 1]);
                    Slots.erase(Slots.begin() + j-1);
                    Sleep(5000);
                    goto povtor;
                }
            }
            else
                goto nachalo;
        }
    }
};
class MagicWell : public Enterprise
{
private:
    int chance;
public:
    MagicWell()
    {
        switch (type)
        {
            case 0: { this->chance = 80; break;}
            case 1: { this->chance  = 70; break;}
            case 2: { this->chance  = 60; break;}
            case 3: { this->chance  = 50; break;}
            case 4: { this->chance  = 40; break;}
            case 5: { this->chance  = 30; break;}
            case 6: { this->chance  = 20; break;}
            case 7: { this->chance  = 10; break;}
        }
    }
    void EnterTheMagicWell(Hero hero)
    {
        system("cln");
        cout << "Сквозь улицы города вы находите странный, замшелый колодец \n";
        cout << "Посмотрев внутрь его, вы замечаете, что на дне распологаются кувшинки, от которых пахнет черемухой \n";
        cout << "Недолго думая, вы решаете... \n";
        povtor:
        cout << "1) Бросить монетку номиналом 50 золотых \n";
        cout << "2) Бросить монетку номиналом 25 золотых \n";
        cout << "3) Бросить монетку номиналом 10 золотых \n";
        cout << "4) Плюнуть в колодец \n";
        cout << "5) Уйти. \n";
        int j;
        cin >> j;
        switch (j)
        {
            case 1:
            {
                if (hero.GetGold()<50) {
                    cout << "У вас недостаточно золота для броска! \n";
                    goto povtor;
                }
                else {
                    int povezlo = Randomize::GetRand(1, 100);
                    if (povezlo <= 20 )
                    {
                        Equipment randvesh;
                        randvesh.NewEquipment();
                        cout << "К вашему удивлению в ведре, опущенном в колодец что-то зашевелилось \n";
                        cout << "Подняв ведро вы понимаете, что вам сегодня повезло, вы нашли в ведре  " << randvesh.GetType() << "\n";
                        cout << "Пока никто не решил зафиксировать акт вандализма, вы в спешке кладете его в свой инвентарь \n \n ";
                        hero.Inventory.push_back(randvesh);
                        goto povtor;
                    }
                    else
                        cout << "Но ничего не произошло..";
                    goto povtor;
                }
                break;
            }
            case 2:
            {
                if (hero.GetGold()<25) {
                    cout << "У вас недостаточно золота для броска! \n";
                    goto povtor;
                }
                else {
                    int povezlo = Randomize::GetRand(1, 100);
                    if (povezlo <= 10 )
                    {
                        Equipment randvesh;
                        randvesh.NewEquipment();
                        cout << "К вашему удивлению в ведре, опущенном в колодец что-то зашевелилось \n";
                        cout << "Подняв ведро вы понимаете, что вам сегодня повезло, вы нашли в ведре  " << randvesh.GetType() << "\n";
                        cout << "Пока никто не решил зафиксировать акт вандализма, вы в спешке кладете его в свой инвентарь \n \n ";
                        hero.Inventory.push_back(randvesh);
                    }
                    else
                        cout << "Но ничего не произошло..";
                    goto povtor;
                }
                break;
            }
            case 3:
            {
                if (hero.GetGold()<10) {
                    cout << "У вас недостаточно золота для броска! \n";
                    goto povtor;
                }
                else {
                    int povezlo = Randomize::GetRand(1, 100);
                    if (povezlo <= 5 )
                    {
                        Equipment randvesh;
                        randvesh.NewEquipment();
                        cout << "К вашему удивлению в ведре, опущенном в колодец что-то зашевелилось \n";
                        cout << "Подняв ведро вы понимаете, что вам сегодня повезло, вы нашли в ведре  " << randvesh.GetType() << "\n";
                        cout << "Пока никто не решил зафиксировать акт вандализма, вы в спешке кладете его в свой инвентарь \n \n ";
                        hero.Inventory.push_back(randvesh);
                    }
                    else
                        cout << "Но ничего не произошло..";
                    goto povtor;
                }
                break;
            }
            case 4:
                {
                    cout << "Вы делаете смачный плевок в самую глубь колодца";
                    int povezlo = Randomize::GetRand(1, 100);
                    if (povezlo <= 30 )
                    {
                        cout << "Совершая прицельный выстрел изо рта, вы не заметили как какой-то зеленый коротышка пробрался к вам в кошель и";
                        if (hero.GetGold() != 0)
                        {
                            hero.SetGold(hero.GetGold()/3);
                            cout << " забрал целых " << hero.GetGold() << " золотых! \n";
                            cout << "Вы донельзя возмущены \n";
                           goto povtor;
                        }
                        else
                            {
                            cout << "возмутившись отсутствием каких-либо монет ушел прочь. Вы чувствуете удовлетворение \n";
                            goto povtor;
                            }
                    }
                    else
                        cout << "Но ничего не произошло \n";
                    goto povtor;
                    break;
                }
            case 5: break;
        }
    }
};
class CityHall : public Enterprise
{
// Todo : Будет доступно в Beta 0.1
};
class KallTraider : public Enterprise
{
 // Todo : Будет доступно в Beta 0.1
};
class Predict : public Enterprise
{
// Todo : Будет доступно в Beta 0.1
};


#endif //MAIN_CPP_ENTERPRISES_H
