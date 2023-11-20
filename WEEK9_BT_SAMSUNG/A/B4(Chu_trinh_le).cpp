1.Chứng minh rằng nếu đồ thị là bipartite, thì nó không chứa chu trình độ dài lẻ:

	Giả sử đồ thị là bipartite, tức là có thể phân chia các đỉnh thành hai tập hợp sao cho không có cạnh nào nối giữa hai đỉnh cùng một tập hợp.
	Bây giờ, giả sử tồn tại một chu trình độ dài lẻ trong đồ thị này.
	Bắt đầu từ một đỉnh bất kỳ trên chu trình, ta sẽ tô các đỉnh xen kẽ giữa hai màu khi di chuyển dọc theo chu trình.
	Do chu trình có độ dài lẻ => ta sẽ kết thúc ở một đỉnh đã được tô màu, nhưng đó lại là màu khác với màu ban đầu. ( Ví dụ ta bắt đầu bằng nút màu xanh thì sau khi kết thúc lần duyệt chu trình lẻ thì nút ban đầu của ta lại là màu đỏ)
	Điều này mâu thuẫn với giả thiết ban đầu rằng đồ thị là bipartite, vì nó có nghĩa là có ít nhất một cạnh nối hai đỉnh cùng màu.
	Do đó, nếu đồ thị là bipartite, nó không thể chứa chu trình độ dài lẻ.

Chứng minh rằng nếu đồ thị không chứa chu trình độ dài lẻ, thì nó là bipartite:

	Giả sử đồ thị không chứa chu trình độ dài lẻ.
	Chọn một đỉnh bất kỳ và tô nó với một màu.
	Tô mọi đỉnh kề với nó bằng màu khác và tiếp tục quy trình này cho tất cả các đỉnh trong đồ thị.
	Nếu tại một thời điểm nào đó, ta phải tô một đỉnh với một màu khác với màu đã chọn trước đó, điều này có nghĩa là tồn tại một chu trình độ dài lẻ.
	Tuy nhiên, theo giả thiết, đồ thị không chứa chu trình độ dài lẻ, nên không có tình huống như vậy xảy ra.
	Do đó, ta có thể tô tất cả các đỉnh bằng hai màu mà không vi phạm quy tắc của đồ thị bipartite.
	Vì vậy, nếu đồ thị không chứa chu trình độ dài lẻ, nó là bipartite.