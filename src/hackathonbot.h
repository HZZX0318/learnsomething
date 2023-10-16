```    //
    // Created by Ethan on 9/13/2023.
    //
    #include <iostream>
    #include "hackathonbot.h"
    #include "action.h"


    Action action;
    HackathonBot::HackathonBot() {
        this->balance = action.getBalance();
        this ->holding - action.getHold();
    }


    long long up = 0, down = 0, upDown = 0, downUp = 0, even = 0, drop = 0;
    double initBuy = 100, prev = 0;


    void initialize() {
        up = 0, down = 0, upDown = 0, downUp = 0, even = 0, drop = 0, prev = 0;
    }

    void HackathonBot::takeAction(float price) {
        if (price<52&&action.getHold()==false&&action.getBalance()>=52) {
            action.buy(price);
            action.updateBalance(price*-1);
            initialize();
            initBuy = price;
            prev = price;
            return;
        }
        if (price>prev) {
            up++;
            down=0;
        }
        if (price<prev) {
            down++;
            up=0;
        }
        if ((up>=52||down>=47)&&action.getHold()==true) {
            action.sell(price);
            action.updateBalance(price);
            initialize();
            prev = price;
            return;
        }
        if (down>=5&&action.getHold()==false&&action.getBalance()>=price) {
            action.buy(price);
            action.updateBalance(price*-1);
            initialize();
            initBuy = price;
            prev = price;
            return;
        }
        if (initBuy*.38>price&&action.getHold()==true) {
            action.sell(price);
            action.updateBalance(price);
            initialize();
            prev = price;
            return;
        }
        if (initBuy*1.89<price&&action.getHold()==true) {
            action.sell(price);
            action.updateBalance(price);
            initialize();
            prev = price;
            return;
        }
        if (price<=prev*1.05&&price>=prev*.95) {
            even++;
        }
        if (even>=10&&action.getHold()==true) {
            action.sell(price);
            action.updateBalance(price);
            initialize();
            prev = price;
            return;
        }
        prev = price;
    }

    double HackathonBot::getBalance() {
        return action.getBalance();
    }

    bool HackathonBot::isHolding() {
        return action.getHold();
    }```