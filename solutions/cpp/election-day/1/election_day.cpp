#include <string>
#include <vector>

namespace election {


struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};
int vote_count(ElectionResult& candidate)
{
    return candidate.votes;
}

void increment_vote_count(ElectionResult& candidate,int vote_increment)
{
    candidate.votes += vote_increment;
}
ElectionResult& determine_result(std::vector<ElectionResult>& final_count)
{
    // Assume at least one element
    ElectionResult* winner = &final_count[0];

    for (auto& candidate : final_count) {
        if (candidate.votes > winner->votes) {
            winner = &candidate;
        }
    }

    // Modify winner in-place
    winner->name = "President " + winner->name;

    return *winner;
}

}  // namespace election
