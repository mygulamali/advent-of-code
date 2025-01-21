#include <limits.h>

#include "06.h"

enum Direction {
    N,
    E,
    S,
    W
};

typedef struct {
    int32_t x;
    int32_t y;
} Position;

typedef struct {
    Position *positions;
    size_t size;
} Positions;

typedef struct {
    Position position;
    enum Direction direction;
} Guard;

Positions find_obstacles(char **lines, const size_t n_lines) {
    const size_t h = n_lines;
    const size_t w = strlen(lines[0]);

    size_t c = 0;
    Position *o = NULL;

    for (size_t i = 0; i < h; i++)
        for (size_t j = 0; j < w; j++)
            if (lines[i][j] == '#') {
                o = (Position *) realloc(o, (c + 1) * sizeof(Position));
                o[c] = (Position) {j, i};
                c++;
            }

    Positions p = {o, c};

    return p;
}

Guard find_guard(
    char **lines,
    const size_t n_lines
) {
    const size_t h = n_lines;
    const size_t w = strlen(lines[0]);

    Guard g;
    for (size_t i = 0; i < h; i++)
        for (size_t j = 0; j < w; j++)
            if (lines[i][j] == '^') {
                g.position = (Position) {j, i};
                g.direction = N;
                return g;
            } else if (lines[i][j] == '>') {
                g.position = (Position) {j, i};
                g.direction = E;
                return g;
            } else if (lines[i][j] == 'v') {
                g.position = (Position) {j, i};
                g.direction = S;
                return g;
            } else if (lines[i][j] == '<') {
                g.position = (Position) {j, i};
                g.direction = W;
                return g;
            }

    // could not find guard
    g.position = (Position) {-1, -1};
    g.direction = N;
    return g;
}

Position find_next_obstacle(const Guard g, const Positions os) {
    Position o;

    switch(g.direction) {
        case N:
            o = (Position) {g.position.x, -1};

            for (size_t i = 0; i < os.size; i++)
                if (
                    os.positions[i].x == g.position.x &&
                    os.positions[i].y < g.position.y &&
                    os.positions[i].y > o.y
                )
                    o.y = os.positions[i].y;
            break;
        case E:
            o = (Position) {INT32_MAX, g.position.y};

            for (size_t i = 0; i < os.size; i++)
                if (
                    os.positions[i].x > g.position.x &&
                    os.positions[i].y == g.position.y &&
                    os.positions[i].x < o.x
                )
                    o.x = os.positions[i].x;
            break;
        case S:
            o = (Position) {g.position.x, INT32_MAX};

            for (size_t i = 0; i < os.size; i++)
                if (
                    os.positions[i].x == g.position.x &&
                    os.positions[i].y > g.position.y &&
                    os.positions[i].y < o.y
                )
                    o.y = os.positions[i].y;
            break;
        case W:
            o = (Position) {-1, g.position.y};

            for (size_t i = 0; i < os.size; i++)
                if (
                    os.positions[i].x < g.position.x &&
                    os.positions[i].y == g.position.y &&
                    os.positions[i].x > o.x
                )
                    o.x = os.positions[i].x;
            break;
    }

    return o;
}

bool valid_obstacle(const Position o) {
    return (-1 < o.x && o.x < INT32_MAX && -1 < o.y && o.y < INT32_MAX);
}

Positions walk_guard(Guard *g, const Position o) {
    size_t n;
    Position *ps;

    switch(g->direction) {
        case N:
            n = g->position.y - o.y - 1;
            ps = (Position *) malloc(n * sizeof(Position));

            for (size_t i = 0; i < n; i++)
                ps[i] = (Position) {g->position.x, g->position.y - i - 1};

            g->position.y = o.y + 1;
            break;
        case E:
            n = o.x - g->position.x - 1;
            ps = (Position *) malloc(n * sizeof(Position));

            for (size_t i = 0; i < n; i++)
                ps[i] = (Position) {g->position.x + i + 1, g->position.y};

            g->position.x = o.x - 1;
            break;
        case S:
            n = o.y - g->position.y - 1;
            ps = (Position *) malloc(n * sizeof(Position));

            for (size_t i = 0; i < n; i++)
                ps[i] = (Position) {g->position.x, g->position.y + i + 1};

            g->position.y = o.y - 1;
            break;
        case W:
            n = g->position.x - o.x - 1;
            ps = (Position *) malloc(n * sizeof(Position));

            for (size_t i = 0; i < n; i++)
                ps[i] = (Position) {g->position.x - i - 1, g->position.y};

            g->position.x = o.x + 1;
            break;
    }

    Positions p = {ps, n};

    return p;
}

void turn_guard(Guard *g) {
    switch(g->direction) {
        case N: // turn N -> E
            g->direction = E;
            break;
        case E: // turn E -> S
            g->direction = S;
            break;
        case S: // turn S -> W
            g->direction = W;
            break;
        case W: // turn W -> N
            g->direction = N;
            break;
    }
}

bool has_position(const Position p, const Positions up) {
    for (size_t i = 0; i < up.size; i++)
        if (p.x == up.positions[i].x && p.y == up.positions[i].y)
            return true;
    return false;
}

// function to find unique positions
void find_unique_positions(const Positions p, Positions *up) {
    for (size_t i = 0; i < p.size; i++)
        if (!has_position(p.positions[i], *up)) {
            up->positions = (Position *) realloc(
                up->positions,
                (up->size + 1) * sizeof(Position)
            );
            up->positions[up->size] = (Position) {p.positions[i].x, p.positions[i].y};
            up->size++;
        }
}

uint32_t day_06_1(const size_t n_lines, char** lines) {
    Positions obstacles = find_obstacles(lines, n_lines);
    Guard guard = find_guard(lines, n_lines);

    Positions unique_positions = {NULL, 0};
    Position next_obstacle = find_next_obstacle(guard, obstacles);
    while(valid_obstacle(next_obstacle)) {
        Positions positions = walk_guard(&guard, next_obstacle);
        find_unique_positions(positions, &unique_positions);
        free(positions.positions);

        turn_guard(&guard);
        next_obstacle = find_next_obstacle(guard, obstacles);
    }

    // final position of the guard off the grid
    switch(guard.direction) {
        case N:
            next_obstacle = (Position) {guard.position.x, -1};
            break;
        case E:
            next_obstacle = (Position) {strlen(lines[0]), guard.position.y};
            break;
        case S:
            next_obstacle = (Position) {guard.position.x, n_lines};
            break;
        case W:
            next_obstacle = (Position) {-1, guard.position.y};
            break;
    }

    Positions positions = walk_guard(&guard, next_obstacle);
    find_unique_positions(positions, &unique_positions);
    free(positions.positions);

    free(obstacles.positions);
    free(unique_positions.positions);

    return unique_positions.size;
}
