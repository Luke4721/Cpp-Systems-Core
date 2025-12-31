#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_down_scores{};
    for(double score : student_scores)
        {
            rounded_down_scores.push_back(static_cast<int>(score));    
        }
    return rounded_down_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count{};
    for(int score : student_scores)
        {
            if(!(score>40))
            {
                count++;
            }
        }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int,4> grade_ranges{};
    
    auto grade_gap{(highest_score-40)/grade_ranges.size()};
    for(size_t i = 0; i<grade_ranges.size();++i)
        {
            if(i==0)
            {
                grade_ranges[i]=41;
            }
            else
            {
                grade_ranges[i]=(grade_ranges[i-1]+(grade_gap));
            }
        }
    return grade_ranges;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranked_list{};
    std::string list_string;
    for(int i = 0; i<student_scores.size();i++)
        {
            list_string = std::to_string(i + 1) + ". " 
                          + student_names[i] + ": " 
                          + std::to_string(student_scores[i]);
            ranked_list.push_back(list_string);
        }
    return ranked_list;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    {
    for (size_t i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";

}
}
