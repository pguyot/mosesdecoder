/*
 * RulePhrase.cpp
 *
 *  Created on: 26 Feb 2014
 *      Author: hieu
 */

#include "RulePhrase.h"
#include "RuleSymbol.h"

using namespace std;

extern bool g_debug;

int RulePhrase::Compare(const RulePhrase &other) const
{
  if (GetSize() != other.GetSize()) {
	return GetSize() < other.GetSize() ? -1 : +1;
  }

  for (size_t i = 0; i < m_coll.size(); ++i) {
	  const RuleSymbol &symbol = *m_coll[i];
	  const RuleSymbol &otherSymbol = *other.m_coll[i];
	  int compare = symbol.Compare(otherSymbol);

	  if (compare) {
		  return compare;
	  }
  }

  return 0;
}
