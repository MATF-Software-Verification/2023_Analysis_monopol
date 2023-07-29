#include <QtTest>
#include <QCoreApplication>
#include <QRandomGenerator>

#include <iostream>

// add necessary includes here
#include <../03-monopol/monopoly/src/player.cpp>
#include <../03-monopol/monopoly/src/field.cpp>
#include <../03-monopol/monopoly/src/bank.cpp>


class monopoly : public QObject
{
    Q_OBJECT

public:
    monopoly();
    ~monopoly();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Class Player

    void testSetNumberOfHousesBuildTrue();
    void testSetNumberOfHousesBuildFalse();
    void testPayToBankSumLessThanBudget();
    void testPayToBankSumMoreThanBudget();
    void testReceiveMoney();
    void testMoveForward();
    void testCalculateTotalWorth();
    void testAddPropertyNotSuccess();
    void testAddPropertySuccess();
    void testPayMortgage();
    void testUpdateNumEstates();
    void testSellProperty();
    void testSellEstate();

    // Class Bank

    void testPaySalary();
    void testBuyEstate();
    void testSellHouse();
    void testBuyProperty();

    // Class Field

    void testDestroyHotel();
    void testDestroyHouse();


};

monopoly::monopoly()
{}

monopoly::~monopoly()
{}

void monopoly::initTestCase()
{}

void monopoly::cleanupTestCase()
{}

void monopoly::testSetNumberOfHousesBuildTrue()
{
    const bool build = true;
    Player* player = new Player(5, "name", 4, 10000);
    int number_of_houses = player->get_number_of_houses();

    int expected_value = number_of_houses + 1;
    player->set_number_of_houses(build);
    int return_value = player->get_number_of_houses();

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testSetNumberOfHousesBuildFalse()
{
    const bool build = false;
    Player* player = new Player(5, "name", 4, 10000);
    int number_of_houses = player->get_number_of_houses();

    int expected_value = number_of_houses;
    player->set_number_of_houses(build);
    int return_value = player->get_number_of_houses();

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testPayToBankSumLessThanBudget()
{
    Player* player = new Player(5, "name", 4, 1000);
    int sum = 1200;

    bool expected_value = false;
    bool return_value = player->pay_to_bank(sum);

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testPayToBankSumMoreThanBudget()
{
    Player* player = new Player(5, "name", 4, 1300);
    int sum = 1200;

    bool expected_value = true;
    bool return_value = player->pay_to_bank(sum);

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testReceiveMoney()
{
    Player* player = new Player(5, "name", 4, 1300);
    int sum = 2000;

    int expected_value = 3300;
    player->receive_money(sum);
    int return_value = player->get_budget();

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testMoveForward()
{
    Player* player = new Player(5, "name", 4, 1000);
    int steps = 1;

    auto expected_value = std::pair(5, false);
    auto return_value = player->move_forward(steps);

    QCOMPARE(return_value.first, expected_value.first);
    QCOMPARE(return_value.second, expected_value.second);

    delete player;
}

void monopoly::testCalculateTotalWorth()
{
    Player* player = new Player(5, "name", 4, 1000);

    int expected_value = 1000;
    int return_value = player->calculate_total_worth();

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testAddPropertyNotSuccess()
{
    Player* player = new Player(5, "name", 4, 1000);
    Field* field = new Field(2, "name", 1200 , 1000 , "", Field_kind::COMMUNITY, 500, 1000);

    bool expected_value = false;
    bool return_value = player->add_property(*field);

    QCOMPARE(return_value, expected_value);

    delete field;
    delete player;
}

void monopoly::testAddPropertySuccess()
{
    Player* player = new Player(5, "name", 4, 1000);
    Field* field = new Field(2, "name", 800 , 1000 , "", Field_kind::COMMUNITY, 500, 1000);

    bool expected_value = true;
    bool return_value = player->add_property(*field);

    QCOMPARE(return_value, expected_value);

    delete field;
    delete player;
}


void monopoly::testPayMortgage()
{
    Player* player = new Player(5, "name", 4, 1000);
    int mortgage = 500;

    bool expected_value = true;
    bool return_value = player->pay_mortgage(mortgage);

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testUpdateNumEstates()
{
    Player* player = new Player(5, "name", 4, 1000);
    bool house = true;

    int expected_value = 1;
    player->update_num_estates(house);
    int return_value = player->get_number_of_houses();

    QCOMPARE(return_value, expected_value);

    delete player;
}

void monopoly::testSellProperty()
{
    Player* player = new Player(5, "name", 4, 1000);
    Field* field = new Field(2, "name", 800 , 1000 , "", Field_kind::COMMUNITY, 500, 1000);
    player->add_property(*field);

    player->sell_property(*field);
    int expected_value = 1000;
    int return_value = player->get_budget();

    QCOMPARE(return_value, expected_value);

    delete field;
    delete player;
}

void monopoly::testSellEstate()
{
    Player* player = new Player(5, "name", 4, 1000);
    Field* field = new Field(2, "name", 8000 , 1000 , "", Field_kind::COMMUNITY, 500, 1000, 1500, 2000);
    bool all = true;

    bool expected_value = true;
    bool return_value = player->sell_estate(*field, all);

    QCOMPARE(return_value, expected_value);

    delete field;
    delete player;
}


void monopoly::testPaySalary()
{
    Bank& bank = Bank::return_bank();

    int expected_value = 20380;
    bank.pay_salary();
    int return_value = bank.get_budget();

    QCOMPARE(return_value, expected_value);
}

void monopoly::testBuyEstate()
{
    Bank& bank = Bank::return_bank();
    int price = 1000;
    bool house = true;

    int expected_value = bank.get_house_counter() + 1;
    bank.buy_estate(price, house);
    int return_value = bank.get_house_counter();

    QCOMPARE(return_value, expected_value);
}

void monopoly::testSellHouse()
{
    Bank& bank = Bank::return_bank();
    int price = 3000;
    bank.buy_estate(price, true);

    bool expected_value = true;
    bool return_value = bank.sell_house(price);

    QCOMPARE(return_value, expected_value);
}

void monopoly::testBuyProperty()
{
    Bank& bank = Bank::return_bank();
    Field* field = new Field(2, "name", 1200 , 1000 , "", Field_kind::COMMUNITY, 500, 1000);

    int expected_value = bank.get_budget() - field->get_price();
    bank.buy_property(*field);
    int return_value = bank.get_budget();

    QCOMPARE(return_value, expected_value);

    delete field;
}

void monopoly::testDestroyHotel()
{
    Field* field = new Field(2, "name", 1200 , 1000 , "", Field_kind::COMMUNITY, 500, 1000);

    bool expected_value = false;
    field->destroy_hotel();
    bool return_value = field->has_hotel();

    QCOMPARE(return_value, expected_value);

    delete field;
}


void monopoly::testDestroyHouse()
{
    Field* field = new Field(2, "name", 1200 , 1000 , "", Field_kind::COMMUNITY, 500, 1000);

    int expected_value = 0;
    field->destroy_house();
    int return_value = field->get_num_of_houses();

    QCOMPARE(return_value, expected_value);

    delete field;
}


QTEST_MAIN(monopoly)

#include "tst_monopoly.moc"
