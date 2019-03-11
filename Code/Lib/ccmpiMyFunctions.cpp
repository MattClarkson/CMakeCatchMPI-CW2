/*=============================================================================

  CMAKECATCHMPI: A software package to demo MPI with CMake, CTest and Catch.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "ccmpiMyFunctions.h"
#include <iostream>
#include <omp.h>

namespace ccmpi {

//-----------------------------------------------------------------------------
void GetFirstAndLastIndex(const int& numberOfThreads,
                          const unsigned long int& i,
                          const double& elementsPerThread,
                          const unsigned long int& numberOfElements,
                          unsigned long int& first,
                          unsigned long int& last)
{
  first = i * elementsPerThread + 1;
  last = ((i + 1) * elementsPerThread + 1) - 1;
  if (last < first) last = first;
  if (last > numberOfElements) last = numberOfElements;
  if (i + 1 == numberOfThreads) last = numberOfElements;
}


//-----------------------------------------------------------------------------
std::vector<std::pair<unsigned long int, unsigned long int> >
GetVectorOfSeriesIndexPairs(const unsigned int& numberOfThreads,
                            const unsigned long int& numberOfElements
                           )
{

  double elementsPerThread = static_cast<double>(numberOfElements)
                           / static_cast<double>(numberOfThreads);

  std::vector<std::pair<unsigned long int, unsigned long int> > v;
  for (int i = 0; i < numberOfThreads; i++)
  {
    unsigned long int first = 0;
    unsigned long int last = 0;
    GetFirstAndLastIndex(numberOfThreads, i, elementsPerThread, numberOfElements, first, last);
    v.push_back(std::pair<unsigned long int, unsigned long int>(first, last));

    std::cout << "For " << numberOfElements << " elements, "
              << " spread over " << numberOfThreads << " processes/threads, "
              << " the i=" << i << " block "
              << " started at " << first
              << " and finished at " << last << std::endl;
  }
  return v;
}


//-----------------------------------------------------------------------------
void FillSeries(unsigned long int* const values, unsigned long int const& numberOfValues)
{
}


//-----------------------------------------------------------------------------
unsigned long int SumSeries(const unsigned long int* const values,
                            unsigned long int const & numberOfValues)
{
  return 0;
}


//-----------------------------------------------------------------------------
double EvaluateGregoryLeibnizSeries(unsigned long int startingTermNumber,
                                    unsigned long int finishingTermNumber
                                   )
{
  return 0.0;
}


//-----------------------------------------------------------------------------
double EvaluatePiUsingOpenMP(unsigned long int numberOfElements)
{
  return 0.0;
}

} // end namespace
