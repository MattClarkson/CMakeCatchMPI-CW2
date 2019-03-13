/*=============================================================================

  CMAKECATCHMPI: A software package to demo MPI with CMake, CTest and Catch.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef ccmpiMyFunctions_h
#define ccmpiMyFunctions_h

#include "ccmpiWin32ExportHeader.h"
#include <vector>

/**
* \file ccmpiMyFunctions.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace ccmpi
{

/**
 * PROVIDED FOR YOU. NO NEED TO IMPLEMENT.
 *
 * \brief Computes a vector of pairs of indexes suitable for splitting a series calculation into batches.
 * \param numberOfThreads the required number of threads or processes to split your processing over.
 * \param numberOfTerms the total number of terms to evaluate in the series.
 *
 * So, for example:
 * \code{.cpp}
 * GetVectorOfSeriesIndexPairs(4, 100)
 * \endcode
 *
 * will return a vector of pairs like: (1, 25), (26, 50), (51, 75), (76, 100).
 *
 * So you can evaluate 100 terms, on 4 threads using the method below.
 */
std::vector<std::pair<unsigned long int, unsigned long int> >
GetVectorOfSeriesIndexPairs(const unsigned int& numberOfThreads,
                            const unsigned long int& numberOfTerms
                           );

/**
 * IMPLEMENT THIS METHOD!!
 *
 * \brief Given a pre-allocated array of values, fills them with values 1, 2, 3 ... numberOfValues.
 * \param values pre-allocated array (meaning the memory must already exist)
 * \param numberOfValues the number of values in the array
 */
void FillSeries(unsigned long int* const values, unsigned long int const& numberOfValues);

/**
 * IMPLEMENT THIS METHOD!!
 *
 * \brief returns the sum of the series.
 * \param values a continuous block of memory containing an array of values
 * \param numberOfValues the number of values in the array
 */
unsigned long int SumSeries(const unsigned long int* const values, unsigned long int const& numberOfValues);

/**
 *
 * IMPLEMENT THIS METHOD!!
 *
 * \brief Evaluates the Gregory-Leibniz Series between a range of terms
 * \param startingTermNumber the index of the term, i.e. 1 for 1st, 2 for 2nd, 3 for 3rd etc.
 * \param finishingTermNumber the index of the term, i.e. 1 for 1st, 2 for 2nd, 3 for 3rd etc.
 *
 * \see https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80
 *
 * So to evaluate the first 3 terms it's:
 * \code{.cpp}
 * double sum = ccmpi::EvaluateGregoryLeibnizSeries(1, 3);
 * \endcode
 * and to evaluate the 1000th to 2000th term it's:
 * \code{.cpp}
 * double sum = ccmpi::EvaluateGregoryLeibnizSeries(1000, 2000);
 * \endcode
 *
 * So, you can compute Pi/4.0 by spreading your processing over say 5 threads,
 * and Wikipedia says you need about 5 billion terms.
 *
 * eg.
 *
 * \code{.cpp}
 * double sum1 = ccmpi::EvaluateGregoryLeibnizSeries(1, 1000000000);
 * double sum2 = ccmpi::EvaluateGregoryLeibnizSeries(1000000001, 2000000000);
 * double sum3 = ccmpi::EvaluateGregoryLeibnizSeries(2000000001, 3000000000);
 * double sum4 = ccmpi::EvaluateGregoryLeibnizSeries(3000000001, 4000000000);
 * double sum5 = ccmpi::EvaluateGregoryLeibnizSeries(4000000001, 5000000000);
 * \endcode
 */
CMAKECATCHMPI_WINEXPORT double EvaluateGregoryLeibnizSeries(unsigned long int startingTermNumber,
                                                            unsigned long int finishingTermNumber
                                                           );

/**
 * IMPLEMENT THIS METHOD!!
 *
 * \brief Computes Pi, using the Gregory Leibniz Series for the specified numberOfElements
 */
CMAKECATCHMPI_WINEXPORT double EvaluatePiUsingOpenMP(unsigned long int numberOfElements);

} // end namespace

#endif
