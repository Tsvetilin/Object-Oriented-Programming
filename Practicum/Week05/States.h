#pragma once

enum class State {
    OK,
    NegativeBalance,
    NegativeQuantity,
    NegativePrice, //Added by me
    UserFull,
    ProductFull,
    PriceFull,
    UserNotFound,
    ProductNotFound,
    ShortOnMoney,
    NotEnoughItems
};