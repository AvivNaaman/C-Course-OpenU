
/* Maximum Length of line */
#define MAX_LINE_LEN 200
/* Maximum count of user's argument */
#define MAX_ARGUMENT_COUNT 3

/* Current command type - NONE=empty line, ERROR=parsing error, all other by mmn definition */
typedef enum cmd_type {
    ERROR, STOP, NONE , READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP,
    MULT_COMP_REAL, MULT_COMP_IMG, MULT_COMP_COMP, ABS_COMP
} cmd_type;

/* Returns the current command type */
cmd_type get_command(char [], char *[3], int *);

/* Returns an enum cmd_type by command text (e.g, for text "read_comp" returns READ_COMP.
 * if unidentified, returns ERROR and prints an error message. */
cmd_type parse_cmd_str_enum(char[]);
