#include "08.h"

typedef struct Position {
    int32_t x;
    int32_t y;
} Position;

typedef struct Antenna {
    char id;
    Position *positions;
    size_t size;
} Antenna;

typedef struct Set {
    Position *positions;
    size_t size;
} Set;

int32_t find_antenna_by_id(const Antenna *a, const size_t n, const char c) {
    for (int32_t i = 0; i < (int32_t) n; i++)
        if (a[i].id == c)
            return i;

    return -1;
}

Antenna * get_antennas(char** lines, const size_t n_lines, size_t *n_antennas) {
    size_t h = n_lines;
    size_t w = strlen(lines[0]);

    size_t n_a = 0;
    Antenna *a = NULL;
    for (size_t i = 0; i < h; i++)
        for (size_t j = 0; j < w; j++)
            if (lines[i][j] != '.') {
                char id = lines[i][j];
                Position p = (Position) { j, i };

                int32_t indx = find_antenna_by_id(a, n_a, id);
                if (indx == -1) {
                    a = realloc(a, (n_a + 1) * sizeof(Antenna));
                    Position * q = (Position *) malloc(sizeof(Antenna));
                    q[0] = p;
                    a[n_a] = (Antenna) { id, q, 1 };
                    n_a++;
                } else {
                    size_t n_p = a[indx].size;
                    a[indx].positions = (Position *) realloc(
                        a[indx].positions,
                        (n_p + 1) * sizeof(Position)
                    );
                    a[indx].positions[n_p] = p;
                    a[indx].size++;
                }
            }

    *n_antennas = n_a;

    return a;
}

void add_position_to_set(const Position p, Set *s) {
    s->positions = (Position *) realloc(s->positions, (s->size + 1) * sizeof(Position));
    if (s->positions == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    s->positions[s->size] = p;
    s->size++;
}

bool valid_position(const Position p, const size_t h, const size_t w) {
    return (-1 < p.x) && (p.x < (int32_t) w) && (-1 < p.y) && (p.y < (int32_t) h);
}

bool position_in_set(const Position p, const Set s) {
    for (size_t i = 0; i < s.size; i++)
        if (s.positions[i].x == p.x && s.positions[i].y == p.y)
            return true;

    return false;
}

uint32_t valid_antinodes(
    const Antenna *a,
    const size_t n,
    const size_t h,
    const size_t w
) {
    Set s = (Set) { NULL, 0 };

    // loop over antenna types
    for (size_t i_a = 0; i_a < n; i_a++)
        // loop over position pairs
        for (size_t i_p = 0; i_p < a[i_a].size - 1; i_p++)
            for (size_t i_q = i_p + 1; i_q < a[i_a].size; i_q++) {
                // first antinode
                Position a_1 = (Position) {
                    2 * a[i_a].positions[i_p].x - a[i_a].positions[i_q].x,
                    2 * a[i_a].positions[i_p].y - a[i_a].positions[i_q].y
                };

                if (valid_position(a_1, h, w) && !position_in_set(a_1, s))
                    add_position_to_set(a_1, &s);

                // second antinode
                Position a_2 = (Position) {
                    2 * a[i_a].positions[i_q].x - a[i_a].positions[i_p].x,
                    2 * a[i_a].positions[i_q].y - a[i_a].positions[i_p].y
                };

                if (valid_position(a_2, h, w) && !position_in_set(a_2, s))
                    add_position_to_set(a_2, &s);
            }

    free(s.positions);

    return s.size;
}

uint32_t day_08_1(const size_t n_lines, char **lines) {
    const size_t height = n_lines;
    const size_t width = strlen(lines[0]);

    size_t n;
    Antenna *antennas = get_antennas(lines, n_lines, &n);

    int32_t result = valid_antinodes(antennas, n, height, width);

    for (size_t i = 0; i < n; i++) free(antennas[i].positions);
    free(antennas);

    return (uint32_t) result;
}
