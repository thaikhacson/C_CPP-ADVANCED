Map là một tập hợp các mục, mỗi mục bao gồm một key và một value . Trong map, tất cả các key được yêu cầu phải là duy nhất nhưng các value có thể lặp lại. Map có ba phương pháp chính:

- thêm cặp key-value được chỉ định
- lấy value cho một key nhất định
- xóa cặp key-value khỏi map

Trong map, các cặp được sắp xếp theo thứ tự key. Tất cả các thao tác chèn, xóa và tìm kiếm đều được thực hiện O(logn), n là số cặp trong map
Trong map không có thứ tự, các cặp không được giữ theo thứ tự được sắp xếp và tất cả các thao tác chèn, xóa và tìm kiếm đều được thực hiện O(1)
Map được sắp xếp được triển khai bằng std::map, muốn lưu map không có thứ tự được triển khai bằng std::unordered_map và muốn lưu nhiều key giống nhau thì dùng multimap	

- Duyệt các phần tử trong map
map<int, int> mp;
mp[100] = 200;
mp.insert({300, 400});

for(pair<int, int> x : mp) {
   cout << x.first << " " << x.second << endl;
}


Set phù hợp khi tìm kiếm, đếm số lượng khác nhau trong mảng
Map phù hợp với bài toán tần suất xuất hiện của từ trong mảng