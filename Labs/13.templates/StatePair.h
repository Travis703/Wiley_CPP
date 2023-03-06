#ifndef STATEPAIR
#define STATEPAIR

template <typename T1, typename T2>

class StatePair
{
private:
    T1 key;
    T2 val;
    // TODO: Define constructors
public:
    StatePair() {}

    StatePair(T1 userKey, T2 userValue)
    {
        key = userKey;
        val = userValue;
    }
    void SetKey(T1 k)
    {
        key = k;
    }
    void SetValue(T2 v)
    {
        val = v;
    }
    T1 GetKey()
    {
        return key;
    }
    T2 GetValue()
    {
        return val;
    }
    // TODO: Define mutators, and accessors for StatePair

    // TODO: Define PrintInfo() method

    void PrintInfo()
    {
        std::cout << val << ": " << key << std::endl;
    }
};

#endif