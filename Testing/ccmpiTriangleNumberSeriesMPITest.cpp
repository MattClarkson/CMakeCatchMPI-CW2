/*=============================================================================

  CMAKECATCHMPI: A software package to demo MPI with CMake, CTest and Catch.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "ccmpiCatchMain.h"
#include "ccmpiMyFunctions.h"
#include "ccmpiExceptionMacro.h"
#include <mpi.h>
#include <memory>

TEST_CASE( "6. MPI Triangle Number Test", "[CW2]" ) {

  int rank = 0;
  int size = 0;
  double sum = 0;
  unsigned long int indexes[2];
  unsigned long int sumBySummingEachSum = 0;
  unsigned long int sumBySummingReturnedMemory = 0;

  // Basic Plan: Practice splitting memory blocks.
  // 1. Create an array of numberOfElements
  // 2. Fill with 1...numberOfElements
  // 3. Split array into multiple blocks, send to each node
  // 4. Each node computes the sum of their block
  // 5. Each node returns their sum to the root which is summed on the root to give a combined total on the root node
  // 6. Each node ALSO returns their memory block to the root node, which should be saved in a different array
  // 7. On the root note, the total of the original array,
  //    returned combined array and the combined total should all be equal
  //    and furthermore should be equal to (n (n+1)) / 2.0

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int numberOfElements = 1000; // you can leave this hard-coded for now, for simplicity.
  int elementsPerProcess = numberOfElements / size;

  // Defensive check - this coursework must have the numberOfElements
  // as an exact multiple of the number of processes, again for simplicity.
  if (numberOfElements % size != 0)
  {
    ccmpiExceptionThrow() << "Number of Elements (" << numberOfElements
                          << "), is not divisible by the number of processes (" << size << ")";

  }

  // https://en.wikipedia.org/wiki/Triangular_number
  unsigned long int expectedTotal = (numberOfElements * (numberOfElements+1)) / 2;

  std::vector<std::pair<unsigned long int, unsigned long int> > v
    = ccmpi::GetVectorOfSeriesIndexPairs(size, numberOfElements);

  unsigned long int* originalArray = nullptr;
  unsigned long int* repopulatedArray = nullptr;
  if (rank == 0)
  {
    originalArray = new unsigned long int[numberOfElements];
    repopulatedArray = new unsigned long int[numberOfElements];

    /////////////////////////////////////////////////////////////////////////////
    // Start of your code
    /////////////////////////////////////////////////////////////////////////////

    // 1. Fill originalArray with 1...n  (implemented in Q1)
    // 2. Check the sum of the series.   (implemented in Q1)

    /////////////////////////////////////////////////////////////////////////////
    // End of your code. [1 mark]
    /////////////////////////////////////////////////////////////////////////////
  }

  unsigned long int* subsetOfArray = new unsigned long int[v[rank].second - v[rank].first + 1];

  /////////////////////////////////////////////////////////////////////////////
  // Start of your code
  /////////////////////////////////////////////////////////////////////////////

  // 1. Send a block of data (subsetOfArray) to all nodes (including root) in the MPI world. [3 marks]
  // 2. Sum the local array subsetOfArray. [1 mark]
  // 3. Send all these local sums back to root, and sum on root. [2 marks]
  // 4. Copy blocks of memory from subsetOfArray on each node into repopulatedArray. [2 marks]
  // 5. On root node only, check the totals [1 mark]
  //    in:
  //        sumBySummingEachSum
  //        sumBySummingReturnedMemory
  //    equal:expectedTotal
  //

  /////////////////////////////////////////////////////////////////////////////
  // End of your code
  /////////////////////////////////////////////////////////////////////////////
}
