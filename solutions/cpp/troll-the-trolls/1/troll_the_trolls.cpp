namespace hellmath {

    enum class AccountStatus : int {
    troll = 0,
    guest = 1,
    user  = 2,
    mod   = 3
};


    enum class Action
    {
    read,
    write,
    remove
    };
    bool display_post(AccountStatus poster, AccountStatus viewer)
    {
        return poster != AccountStatus::troll || poster == viewer;
    }

    bool permission_check(Action action, AccountStatus status)
    {
        switch (status) {
            case AccountStatus::mod:
                return true;
    
            case AccountStatus::guest:
                return action == Action::read;
    
            case AccountStatus::user:
            case AccountStatus::troll:
                return action != Action::remove;
        }
        return false; // defensive: unreachable
    }

    bool valid_player_combination(AccountStatus p1, AccountStatus p2)
    {
        if (p1 == AccountStatus::guest || p2 == AccountStatus::guest)
            return false;
    
        if (p1 == AccountStatus::troll || p2 == AccountStatus::troll)
            return p1 == p2;
    
        return true;
    }

    bool has_priority(AccountStatus user1, AccountStatus user2)
    {
        auto rank1 = static_cast<int>(user1);
        auto rank2 = static_cast<int>(user2);
        return rank1>rank2;
    }
// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.

}  // namespace hellmath
