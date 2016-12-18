#include"Key.h"

Key::Key(int val) {
	if (val < 0)
		value = -val;
	else
		value = val;
}

bool operator<(const Key& k1, const Key& k2) {
	return k1.value < k2.value;
}

bool operator<=(const Key& k1, const Key& k2) {
	return k1.value <= k2.value;
}

bool operator>(const Key& k1, const Key& k2) {
	return k1.value > k2.value;
}

bool operator>=(const Key& k1, const Key& k2) {
	return k1.value >= k2.value;
}

bool operator==(const Key& k1, const Key& k2) {
	return k1.value == k2.value;
}

bool operator!=(const Key& k1, const Key& k2) {
	return k1.value != k2.value;
}

std::ostream& operator<<(std::ostream& out, const Key& k) {
	if (k.value == 0)
		return out << "";
	else
		return out << k.value;
}