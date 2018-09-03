/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "lsmrDense.h"

#include <iostream>

#include <cstdlib>
#include <cmath>

#include <fstream>


//
// A more interesting testing case, but still a basic one.
//
int lsmrTest2( int , char * [] )
{

  lsmrDense solver;

  const double eps = 1e-15;

  solver.SetOutputStream( std::cout );
  solver.SetEpsilon( eps );
  solver.SetDamp( 0.0 );
  solver.SetMaximumNumberOfIterations( 100 );
  solver.SetToleranceA( 1e-16 );
  solver.SetToleranceB( 1e-16 );
  solver.SetUpperLimitOnConditional( 1.0 / ( 10 * sqrt( eps ) ) );


  const unsigned int mm = 300000;
  const unsigned int nn = 100000;
  const unsigned int dataSize = 1000000;

  float AValue[dataSize];
  int rowIndex[dataSize];
  int columnIndex[dataSize];

  double bb[mm];
  double xx[nn];
  
  std::ifstream b_file;
  b_file.open("b.txt");
  for (int i = 0; i < mm; i++) {
    b_file >> bb[i];
    // std::cout << std::endl << "FUCK OFF." << std::endl;
    // std::cout << rowIndex[i]<<", "<<columnIndex[i] << ", " << AValue[i] << std::endl;
  }


  // bb[0] = 7.0;
  // bb[1] =-7.0;
  // bb[2] = 2.0;

  //  -3  5
  typedef double * RowType;
  RowType A[mm];

  double AA[dataSize];

  std::ifstream A_file;
  A_file.open("A.txt");
  for (int i = 0; i < dataSize; i++) {
    A_file >> rowIndex[i] >> columnIndex[i] >> AValue[i];
    // std::cout << std::endl << "FUCK OFF." << std::endl;
    // std::cout << AValue[i] << std::endl;
    // std::cout << rowIndex[i] <<", "<<columnIndex[i] << ", " << AValue[i] << std::endl;
  }

  // for (int i = 0; i < dataSize; ++i)
  // {
  //   std::cout << std::endl << "WTF?!" << std::endl;
  //   std::cout << columnIndex[i] << std::endl;
  // }


  // int c = 0;
  // A[0] = &(AA[0]);
  // A[1] = &(AA[2]);
  // A[2] = &(AA[4]);
  for (int i = 0; i < mm; ++i)
  {
    A[i] = &(AA[i*nn]);
  }
  // for (int i = 0; i < 3; ++i)
  // {
  //   // A[i] = &(AA[i*2]);
  //   for (int j = 0; j < 2; ++j)
  //   {
  //     std::cout << std::endl << "FUCK OFF." << std::endl;
  //     std::cout << rowIndex[i] << std::endl;
  //     std::cout << columnIndex[j] << std::endl;
  //     // std::cout << c << std::endl;
  //     std::cout << AValue[c] << std::endl;
  //     A[rowIndex[i]][columnIndex[j]] = AValue[c];
  //     c++;
  //   }
  // }

  for (int i = 0; i < mm; ++i)
  {
    for (int j = 0; j < nn; ++j)
    {
      A[i][j] = 0.0;
    }
  }

  for (int i = 0; i < dataSize; ++i)
  {
    // std::cout << std::endl << "FUCK OFF." << std::endl;
    // std::cout << rowIndex[i] << std::endl;
    // std::cout << columnIndex[i] << std::endl;
    // std::cout << AValue[i] << std::endl;
    // std::cout << 2.0 << std::endl;
    A[rowIndex[i]][columnIndex[i]] = AValue[i];
  }


  // A[0] = &(AA[0]);
  // A[1] = &(AA[2]);
  // A[2] = &(AA[4]);
  // A[0][0] = 1.0;
  // A[0][1] = 2.0;
  // A[1][0] = 4.0;
  // A[1][1] = 1.0;
  // A[2][0] = 1.0;
  // A[2][1] = 1.0;
  solver.SetMatrix( A );

  solver.Solve( mm, nn, bb, xx );
  std::cout << std::endl << "FUCK OFF." << std::endl;

  std::cout << "Stopped because " << solver.GetStoppingReason() << ": " << solver.GetStoppingReasonMessage() << std::endl;
  std::cout << "Used " << solver.GetNumberOfIterationsPerformed() << " Iterations" << std::endl;
  std::cout << "Frobenius norm estimation of Abar = " << solver.GetFrobeniusNormEstimateOfAbar() << std::endl;
  std::cout << "Condition number estimation of Abar = " << solver.GetConditionNumberEstimateOfAbar() << std::endl;
  std::cout << "Estimate of final value of norm(rbar) = " << solver.GetFinalEstimateOfNormRbar() << std::endl;
  std::cout << "Estimate of final value of norm of residuals = " << solver.GetFinalEstimateOfNormOfResiduals() << std::endl;
  std::cout << "Estimate of norm of final solution = " << solver.GetFinalEstimateOfNormOfX() << std::endl;
  std::cout << "Solution = xx = " << xx[0] << " " << xx[1] << std::endl;

  // readA();
  return EXIT_SUCCESS;
}

