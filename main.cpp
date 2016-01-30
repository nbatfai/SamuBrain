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


#include <QApplication>
#include "SamuLife.h"

int main ( int argc, char** argv )
{
  QApplication app ( argc, argv );
  SamuLife samulife ( 34, 16 );
  samulife.show();
  return app.exec();
}
