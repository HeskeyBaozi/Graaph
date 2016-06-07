#pragma once
#include <string>
class Vertex
{
public:
	explicit Vertex(const std::string& label);
	Vertex(const Vertex& other);
	~Vertex();

	/* operation */
	friend bool operator<(const Vertex& lhs, const Vertex& rhs);
	friend bool operator==(const Vertex& lhs, const Vertex& rhs);
	friend bool operator!=(const Vertex& lhs, const Vertex& rhs);

	/* Getter */
	std::string getLabel() const;
private:
	std::string __label;
};

