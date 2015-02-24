/*****************************************************************************
 * Copyright (C) 2011-2015 Michael Ira Krufky
 *
 * Author: Michael Ira Krufky <mkrufky@linuxtv.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

#ifndef _TOT_H__
#define _TOT_H__

#include "table.h"

#ifndef _DVBPSI_TOT_H_
#include "dvbpsi/tot.h"
#endif

namespace dvbtee {

namespace decode {

/* TDT (Time and Date Table)/TOT (Time Offset Table) */

class TOT_Watcher;

class tot: public Table/*<dvbpsi_tot_t>*/ {
public:
	tot(Decoder *);
	tot(Decoder *, TOT_Watcher*);
	tot(Decoder *, TOT_Watcher*, dvbpsi_tot_t*);
	tot(Decoder *, dvbpsi_tot_t*);
	virtual ~tot();

	const time_t& getTime() const { return m_time; }

	void store(dvbpsi_tot_t*);
private:
	time_t m_time;
};

class TOT_Watcher: public TableWatcher/*<0xcd, tot>*/ {
public:
	TOT_Watcher() {}
	virtual ~TOT_Watcher() {}

	//virtual void updateTable(uint8_t tId, Table*);
	virtual void updateTOT(tot&) = 0;
};

}

}

#endif /* _TOT_H__ */