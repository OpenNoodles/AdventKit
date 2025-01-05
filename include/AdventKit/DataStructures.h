
#pragma once


#include "../../src/Lines.h"
#include "../../src/LMatrix.h"

#include "../../src/VMatrix.h"
template<> class VMatrix<char>;

#include "../../src/Walker.h"
template<> class Walker<Lines>;
template<> class Walker<VMatrix<char>>;
