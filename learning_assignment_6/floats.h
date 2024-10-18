#ifndef FLOATS_H
#define FLOATS_H

typedef enum encoding_types{
    special = -1,
    denormalized = 0,
    normalized = 1
}encoding_type;

encoding_type get__encoding_type(float input);


#endif