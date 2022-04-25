//
// Created by oleg on 20.04.22.
//
#include <gtest/gtest.h>
#include <Transaction.h>
#include <Account.h>

TEST(Account, GetBalance){
    Account Den(1,100);
    EXPECT_EQ(Den.GetBalance(), 100);
    Den.Lock();
    Den.ChangeBalance(-30);
    Den.Unlock();
    EXPECT_EQ(Den.GetBalance(), 90);
    
}

TEST(Account, ChangeBalance){
    Account Vanya(0, 100);
    EXPECT_THROW(Vanya.ChangeBalance(50), std::runtime_error);
   Vanya.Lock();
    Vanya.ChangeBalance(50);
    EXPECT_EQ(Vanya.GetBalance(), 150);

}

TEST(Account, Lock){
    Account Kirill(0, 100);
    Kirill.Lock();
    EXPECT_THROW(Kirill.Lock(), std::runtime_error);
}



