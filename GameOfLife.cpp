/**
 * @brief Samu has learnt the rules of Conway's Game of Life
 *
 * @file GameOfLife.h
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


#include "GameOfLife.h"

GameOfLife::GameOfLife ( int w, int h ) : m_w ( w ), m_h ( h )
{

  lattices = new int**[2];

  lattices[0] = new int*[m_h];
  for ( int i {0}; i<m_h; ++i )
    {
      lattices[0][i] = new int [m_w];
    }

  lattices[1] = new int*[m_h];

  for ( int i {0}; i<m_h; ++i )
    {
      lattices[1][i] = new int [m_w];
    }

  predictions = new int*[m_h];

  for ( int i {0}; i<m_h; ++i )
    {
      predictions[i] = new int [m_w];
    }

  latticeIndex = 0;

  int ** lattice = lattices[latticeIndex];

  for ( int i {0}; i<m_h; ++i )
    for ( int j {0}; j<m_w; ++j )
      {
        lattice[i][j] = 0;
      }

  samuBrain = new SamuBrain ( m_w, m_h );

  carx = 0;
  manx = m_w/2;
  housex = 2*m_w/5;

}

GameOfLife::~GameOfLife()
{
  for ( int i {0}; i<m_h; ++i )
    {
      delete[] lattices[0][i];
      delete[] lattices[1][i];
      delete[] predictions[i];
    }

  delete[] predictions;
  delete[] lattices[0];
  delete[] lattices[1];
  delete[] lattices;

  delete samuBrain;
}


int ** GameOfLife::lattice()
{
  return lattices[latticeIndex];
}

void GameOfLife::run()
{
  while ( true )
    {
      QThread::msleep ( m_delay );

      if ( !paused )
        {

          ++m_time;

          qDebug() << "<<<" << m_time << "<<<";

          development();

          if ( samuBrain )
            {
              samuBrain->learning ( lattices[latticeIndex], predictions );
              qDebug() << m_time
                       << "   #MPUs:" << samuBrain->nofMPUs()
                       << "Observation (MPU):" << samuBrain->get_foobar().c_str();
            }

          //latticeIndex = ( latticeIndex+1 ) %2;
          emit cellsChanged ( lattices[latticeIndex], predictions );
          latticeIndex = ( latticeIndex+1 ) %2;

          qDebug() << ">>>" << m_time << ">>>";

        }
    }

}

void GameOfLife::pause()
{
  paused = !paused;
}

int GameOfLife::numberOfNeighbors ( int **lattice, int r, int c, int state )
{
  int number {0};

  for ( int i {-1}; i<2; ++i )
    for ( int j {-1}; j<2; ++j )

      if ( ! ( ( i==0 ) && ( j==0 ) ) )
        {
          int o = c + j;
          if ( o < 0 )
            {
              o = m_w-1;
            }
          else if ( o >= m_w )
            {
              o = 0;
            }

          int s = r + i;
          if ( s < 0 )
            {
              s = m_h-1;
            }
          else if ( s >= m_h )
            {
              s = 0;
            }

          if ( lattice[s][o] == state )
            {
              ++number;
            }
        }

  return number;
}


void GameOfLife::clear_lattice ( int **nextLattice )
{
  for ( int i {0}; i<m_h; ++i )
    for ( int j {0}; j<m_w; ++j )
      {
        nextLattice[i][j] = 0;
      }
}

void GameOfLife::fill_lattice ( int **nextLattice, int color )
{
  for ( int i {0}; i<m_h; ++i )
    for ( int j {0}; j<m_w; ++j )
      {
        nextLattice[i][j] = color;
      }
}

void GameOfLife::control_Conway ( int **prevLattice, int **nextLattice )
{
  for ( int i {0}; i<m_h; ++i )

    for ( int j {0}; j<m_w; ++j )
      {

        int liveNeighbors = numberOfNeighbors ( prevLattice, i, j, true );

        if ( prevLattice[i][j] == true )
          {
            if ( liveNeighbors==2 || liveNeighbors==3 )
              {
                nextLattice[i][j] = true;
              }
            else
              {
                nextLattice[i][j] = false;
              }
          }
        else
          {
            if ( liveNeighbors==3 )
              {
                nextLattice[i][j] = true;
              }
            else
              {
                nextLattice[i][j] = false;
              }
          }
      }
}

void GameOfLife::control_Movie ( int **nextLattice )
{
  if ( carx < m_w-5 )
    {
      carx += 2;
    }
  else
    {
      carx = 0;
    }

  if ( manx < m_w-3 )
    {
      ++manx;
    }
  else
    {
      manx = 0;
    }

  house ( nextLattice, housex, 3*m_h/5 -6 );
  car ( nextLattice, carx, 3*m_h/5 +1 );
  man ( nextLattice, manx, 3*m_h/5-1 );

}

void GameOfLife::control_Stroop ( int **nextLattice )
{
  if ( ++age <20 )
    {
      red ( nextLattice, 2, 5, 1 );
    }
  else if ( age <40 )
    {
      green ( nextLattice, 2, 5, 1 );
    }
  else if ( age <60 )
    {
      blue ( nextLattice, 2, 5, 1 );
    }
  else if ( age <80 )
    {
      red ( nextLattice, 2, 5, 2 );
    }
  else if ( age <100 )
    {
      green ( nextLattice, 2, 5, 2 );
    }
  else if ( age <120 )
    {
      blue ( nextLattice, 2, 5, 2 );
    }
  else if ( age <140 )
    {
      red ( nextLattice, 2, 5, 3 );
    }
  else if ( age <160 )
    {
      green ( nextLattice, 2, 5, 3 );
    }
  else if ( age <180 )
    {
      blue ( nextLattice, 2, 5, 3 );
    }
  else
    {
      age =0;
      red ( nextLattice, 2, 5, 2 );
    }

}

void GameOfLife::development()
{

  int **prevLattice = lattices[latticeIndex];
  int **nextLattice = lattices[ ( latticeIndex+1 ) %2];

  clear_lattice ( nextLattice );

  if ( m_time == 1 )
    {
      //clear_lattice ( nextLattice );

      glider ( nextLattice, 2*m_w/5, 2*m_h/5 );
      glider ( nextLattice, 3*m_w/5, 3*m_h/5 );
      glider ( nextLattice, 4*m_w/5, 4*m_h/5 );
      glider ( nextLattice, 4*m_w/5, 2*m_h/5 );
      glider ( nextLattice, 2*m_w/5, 4*m_h/5 );

    }
  else if ( m_time < 30000 )
    {
      control_Conway ( prevLattice, nextLattice );
    }
  else if ( m_time < 65000 )
    {
      control_Stroop ( nextLattice );
    }
  else if ( m_time < 100000 )
    {
      control_Movie ( nextLattice );
    }
  else
    {
      m_time = -1;
    }

}

void GameOfLife::red ( int **lattice, int x, int y, int color )
{

  int r[7][17] =
  {
    {1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0},
    {1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0},
    {1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,1,1,0,0,0,1,1,1,1,0,0,1,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0},
    {1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0}
  };

  for ( int i {0}; i<7; ++i )
    {
      for ( int j {0}; j<17; ++j )
        {
          if ( r[i][j] )
            {
              lattice[y+i][x+j] = r[i][j]*color;
            }
        }

    }
}

void GameOfLife::green ( int **lattice, int x, int y, int color )
{

  int r[7][29] =
  {
    {0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,1},
    {1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1},
    {1,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,1,0,1},
    {1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1},
    {1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1},
    {0,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,1}
  };

  for ( int i {0}; i<7; ++i )
    {
      for ( int j {0}; j<29; ++j )
        {

          if ( r[i][j] )
            {
              lattice[y+i][x+j] = r[i][j]*color;
            }
        }

    }
}

void GameOfLife::blue ( int **lattice, int x, int y, int color )
{

  int r[7][21] =
  {
    {1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,1},
    {1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
    {1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
    {1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0},
    {1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
    {1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
    {1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1}

  };

  for ( int i {0}; i<7; ++i )
    {
      for ( int j {0}; j<21; ++j )
        {
          if ( r[i][j] )
            {
              lattice[y+i][x+j] = r[i][j]*color;
            }
        }

    }
}

void GameOfLife::glider ( int **lattice, int x, int y )
{

  lattice[y+0][x+2] = 1;
  lattice[y+1][x+1] = 1;
  lattice[y+2][x+1] = 1;
  lattice[y+2][x+2] = 1;
  lattice[y+2][x+3] = 1;

}

void GameOfLife::house ( int **lattice, int x, int y )
{

  lattice[y+0][x+3] = 1;

  lattice[y+1][x+2] = 1;
  lattice[y+1][x+4] = 1;

  lattice[y+2][x+1] = 1;
  lattice[y+2][x+5] = 1;

  lattice[y+3][x+0] = 1;
  lattice[y+3][x+6] = 1;

  lattice[y+4][x+0] = 1;
  lattice[y+4][x+6] = 1;

  lattice[y+5][x+0] = 1;
  lattice[y+5][x+6] = 1;

  lattice[y+6][x+0] = 1;
  lattice[y+6][x+6] = 1;

  lattice[y+7][x+0] = 1;
  lattice[y+7][x+6] = 1;

  lattice[y+8][x+0] = 1;
  lattice[y+8][x+1] = 1;
  lattice[y+8][x+2] = 1;
  lattice[y+8][x+3] = 1;
  lattice[y+8][x+4] = 1;
  lattice[y+8][x+5] = 1;
  lattice[y+8][x+6] = 1;
}

void GameOfLife::man ( int **lattice, int x, int y )
{

  lattice[y+0][x+1] = 1;

  lattice[y+1][x+0] = 1;
  lattice[y+1][x+1] = 1;
  lattice[y+1][x+2] = 1;

  lattice[y+2][x+1] = 1;

  lattice[y+3][x+0] = 1;
  lattice[y+3][x+2] = 1;

}

void GameOfLife::car ( int **lattice, int x, int y )
{

  lattice[y+0][x+1] = 1;
  lattice[y+0][x+2] = 1;
  lattice[y+0][x+3] = 1;

  lattice[y+1][x+0] = 1;
  lattice[y+1][x+1] = 1;
  lattice[y+1][x+2] = 1;
  lattice[y+1][x+3] = 1;
  lattice[y+1][x+4] = 1;

  lattice[y+2][x+1] = 1;
  lattice[y+2][x+3] = 1;

}

int GameOfLife::getW() const
{
  return m_w;
}
int GameOfLife::getH() const
{
  return m_h;
}
long GameOfLife::getT() const
{
  return m_time;
}













