/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: jsy.h
  Source: jsy.idl
  Cyclone DDS: V0.9.0

*****************************************************************/
#ifndef DDSC_JSY_H
#define DDSC_JSY_H

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DDS_SEQUENCE_INT8_DEFINED
#define DDS_SEQUENCE_INT8_DEFINED
typedef struct dds_sequence_int8
{
  uint32_t _maximum;
  uint32_t _length;
  int8_t *_buffer;
  bool _release;
} dds_sequence_int8;

#define dds_sequence_int8__alloc() \
((dds_sequence_int8*) dds_alloc (sizeof (dds_sequence_int8)));

#define dds_sequence_int8_allocbuf(l) \
((int8_t *) dds_alloc ((l) * sizeof (int8_t)))
#endif /* DDS_SEQUENCE_INT8_DEFINED */

typedef struct ProtoData
{
  char * proto_type_name;
  double timestamp;
  dds_sequence_int8 data;
} ProtoData;

extern dds_topic_descriptor_t ProtoData_desc;

#define ProtoData__alloc() \
((ProtoData*) dds_alloc (sizeof (ProtoData)));

#define ProtoData_free(d,o) \
dds_sample_free ((d), &ProtoData_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_JSY_H */
