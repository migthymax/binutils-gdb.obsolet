/* VxWorks support for ELF
   Copyright (C) 2005-2023 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* This file provides routines used by all VxWorks targets.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf-amigaos.h"
#include "elf/amigaos.h"

/* Add dynamic tags
   AmigaOS: Flag it as a version 2 dynamic binary */  

bool
_bfd_elf_amigaos_add_dynamic_tags (struct bfd_link_info *info)
{
#ifdef DEBUG
		printf ("Target amigaos-pcc needs addtional marker symbol DT_AMIGAOS_DYNVERSION to mark version used.\n"); 
#endif

	struct elf_link_hash_table *htab = elf_hash_table (info);
	
	return  htab->target_os != is_amigaos || _bfd_elf_add_dynamic_entry (info,DT_AMIGAOS_DYNVERSION, 2);
}
 