#ifndef DMGCPU_H
#define DMGCPU_H


class DMGCPU
{
    public:
        DMGCPU();
        ~DMGCPU();

    void ConnectBus(Bus *n) { bus = n; }

    private:
        Bus *bus = nullptr;


};

#endif // DMGCPU_H
