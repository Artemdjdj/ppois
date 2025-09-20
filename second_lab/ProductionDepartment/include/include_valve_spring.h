
#ifndef INCLUDE_VALVE_SPRING_H
#define INCLUDE_VALVE_SPRING_H
class ValveSpring {
private:
    int diameter{0};
    int length{0};
    int count_of_coils{0};
    bool is_compressed{false};
public:
    ValveSpring();
    ValveSpring(int diameter, int length, int count_of_coils, bool is_compressed);
    bool set_all_parameters(int diameter, int length, int count_of_coils);
    void compress();
    void decompress();
    int get_diameter() const;
    int get_count_of_coils() const;
    int get_length() const;
    bool check_is_compressed() const;
    double dist_between_neighbours() const;
};
#endif //INCLUDE_VALVE_SPRING_H
