#ifndef GameOfLife_H
#define GameOfLife_H

/**
 * @brief Samu has learnt the rules of Conway's Game of Life
 *
 * @file GameOfLife.h
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2015, 2016 Norbert Bátfai, batfai.norbert@inf.unideb.hu, nbatfai@gmail.com
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
#include "SamuBrain.h"

class GameOfLife : public QThread
{
    Q_OBJECT

    int m_w {40}, m_h {30};

    int ***lattices;
    int latticeIndex;
    int **predictions;

    SamuBrain* samuBrain;

    long m_time {0};
    int m_delay {1};//{15};
    long age {0};

    bool paused {false};

    void development();
    int  numberOfNeighbors ( int **lattice, int r, int c, int s );

    void glider ( int **lattice, int x, int y );
    void car ( int **lattice, int x, int y );
    void man ( int **lattice, int x, int y );
    void house ( int **lattice, int x, int y );

    int carx {0};
    int manx {0};
    int housex {0};

    void red ( int **lattice, int x, int y, int color );
    void green ( int **lattice, int x, int y, int color );
    void blue ( int **lattice, int x, int y, int color );

    void clear_lattice ( int **nextLattice );
    void fill_lattice ( int **nextLattice, int color );

    void control_Stroop ( int **nextLattice );
    void control_Conway ( int **, int **nextLattice );
    void control_Movie ( int **nextLattice );

public:
    GameOfLife ( int w = 30, int h = 20 );
    ~GameOfLife();

    void run();
    int **lattice();
    int getW() const;
    int getH() const;
    long getT() const;
    void pause();
    int getDelay() const {
        return m_delay;
    }
    void setDelay ( int delay ) {
        if ( delay > 0 ) {
            m_delay = delay;
        }
    }

signals:
    void cellsChanged ( int **, int **, int **, int ** );

};

#endif // GameOfLife_H
