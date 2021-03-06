/*
 * Copyright © 2010 Codethink Limited
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the licence, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Ryan Lortie <desrt@desrt.ca>
 */

#ifndef __gvdb_reader_h__
#define __gvdb_reader_h__

#include <glib.h>

typedef struct _GvdbTable GvdbTable;

G_GNUC_INTERNAL
GvdbTable *             gvdb_table_new                                  (const gchar  *filename,
                                                                         gboolean      trusted,
                                                                         GError      **error);
G_GNUC_INTERNAL
GvdbTable *             gvdb_table_ref                                  (GvdbTable    *table);
G_GNUC_INTERNAL
void                    gvdb_table_unref                                (GvdbTable    *table);

G_GNUC_INTERNAL
gchar **                gvdb_table_list                                 (GvdbTable    *table,
                                                                         const gchar  *key);
G_GNUC_INTERNAL
GvdbTable *             gvdb_table_get_table                            (GvdbTable    *table,
                                                                         const gchar  *key);
G_GNUC_INTERNAL
GVariant *              gvdb_table_get_value                            (GvdbTable    *table,
                                                                         const gchar  *key);

G_GNUC_INTERNAL
gboolean                gvdb_table_has_value                            (GvdbTable    *table,
                                                                         const gchar  *key);

typedef void          (*GvdbWalkValueFunc)                              (const gchar       *name,
                                                                         gsize              name_len,
                                                                         GVariant          *value,
                                                                         gpointer           user_data);
typedef gboolean      (*GvdbWalkOpenFunc)                               (const gchar       *name,
                                                                         gsize              name_len,
                                                                         gpointer           user_data);
typedef void          (*GvdbWalkCloseFunc)                              (gpointer           user_data);

void                    gvdb_table_walk                                 (GvdbTable         *table,
                                                                         const gchar       *key,
                                                                         GvdbWalkOpenFunc   open_func,
                                                                         GvdbWalkValueFunc  value_func,
                                                                         GvdbWalkCloseFunc  close_func,
                                                                         gpointer           user_data);


#endif /* __gvdb_reader_h__ */
