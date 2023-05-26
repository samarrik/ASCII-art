#ifndef CHANNEL
#define CHANNEL

#include "cimage.h"

class CChannel : public CFilter {
public:
    CChannel ( string src = "" );

    ~CChannel() = default;

    void apply ( CImage & src ) override;

    CFilter * clone () override;

private:
    string m_channel = "n";
};

#endif //CHANNEL
