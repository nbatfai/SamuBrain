#ifndef SamuBrain_H
#define SamuBrain_H

/**
 * @brief Samu has learnt the rules of Conway's Game of Life
 *
 * @file SamuBrain.h
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2015, 2016 Norbert Bátfai, batfai.norbert@inf.unideb.hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * SamuBrain, exp. 4, cognitive mental organs: MPU (Mental Processing Unit), Q-- lerning, acquiring higher-order knowledge
 *
 * This is an example of the paper entitled "Samu in his prenatal development".
 *
 * Previous experiments
 *
 * Samu (Nahshon)
 * http://arxiv.org/abs/1511.02889
 * https://github.com/nbatfai/nahshon
 *
 * SamuLife
 * https://github.com/nbatfai/SamuLife
 * https://youtu.be/b60m__3I-UM
 *
 * SamuMovie
 * https://github.com/nbatfai/SamuMovie
 * https://youtu.be/XOPORbI1hz4
 *
 * SamuStroop
 * https://github.com/nbatfai/SamuStroop
 * https://youtu.be/6elIla_bIrw
 * https://youtu.be/VujHHeYuzIk
 */

#include <QThread>
#include <QDebug>
#include <sstream>
#include "SamuQl.h"
#include <vector>
#include <set>
#include <cstdlib>

class Habituation
{
    int mem {0};
    int err {0};

    static const int convergence_limit {
        //4000
        300
    };
    static const int error_limit {
        7
    };

    constexpr static int ma_limit {3};

    int msum[ma_limit];
    int asum[ma_limit];

    int masum {0};
    int mavsum {0};

public:

    Habituation() {
        clear();
    }

    bool is_habituation ( int , int , double & );
    bool is_newinput ( int sum, int vsum );
    void clear() {
        mem = 0;
        err = 0;

        for ( int ci {0}; ci<ma_limit; ++ci ) {
            msum[ci] = asum[ci] = 0;
        }

    }

};

typedef QL** MPU;

class MentalProcessingUnit
{
    int m_w {40}, m_h {30};
    MPU m_samuQl;
    Habituation m_habi;

    int **m_prev;
    int** fr;
    int** fp;

public:
    MentalProcessingUnit ( int w = 30, int h = 20 );
    ~MentalProcessingUnit();

    MPU getSamu() {
        return m_samuQl;
    }
    int ** getPrev() {
        return m_prev;
    }
    int ** getFp() {
        return fp;
    }
    int ** getFr() {
        return fr;
    }
    Habituation& getHabituation() {
        return m_habi;
    }

    void cls();

};

typedef MentalProcessingUnit* MORGAN;

class SamuBrain
{

    int m_w {40};
    int m_h {30};

    std::map<std::string, MORGAN> m_brain;
    MORGAN m_morgan;

    bool m_haveAlreadyLearnt {false};
    bool m_searching {false};
    long m_internal_clock {0};
    int m_haveAlreadyLearntTime {0};
    int m_maxLearningTime {0};
    int m_searchingStart {0};
    bool m_habituation {false};

    MORGAN newMPU ();
    int pred ( int **reality, int **predictions, int, int & );
    int pred ( MORGAN, int **reality, int **predictions, int, int & );
    void init_MPUs ( bool ex );
    std::string get_foobar ( MORGAN ) const;

    int *** fp;
    int *** fr;

public:
    SamuBrain ( int w = 30, int h = 20 );
    ~SamuBrain();

    void learning ( int **reality, int **predictions, int*** fp, int *** fr );
    int getW() const;
    int getH() const;
    bool isSearching() const;
    int nofMPUs() const;
    std::string get_foobar() const;

    bool isHabituation() const {
        return m_habituation;
    }

};

#endif
