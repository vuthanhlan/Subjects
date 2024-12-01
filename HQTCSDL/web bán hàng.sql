--1,Bảng role
		-id: int->Khóa chính tự tăng
		-name: string(varchar)-20 ký tự
2, Bảng Uer
	-id: int->khóa chính tự tăng
	-fullname->string->50 ký tự
	-email-> string->150 ký tự
	-role_id ->int ->foreign key->role(id)
	-created_at: datetime->ngày tạo bản ghi
	-updated_at: datetime->ngày sửa bản ghi
3, Bảng Danh Mục->category
	-id: int->khóa tự tăng
	-name: string->100 ký tự
4, Bảng sản phẩm->Product
	-id: int->Khoa tự tăng
	-title: string->350 ký tự
	-price: int
	-created_at: datetime->ngày tạo bản ghi
	-updated_at: datetime->ngày sửa bản ghi
5, Bảng quản lý phản hồi->contact
	-id: int->Khóa tự tăng
	-name: string->30 ký tự
	-email-> string->150 ký tự
	-note->string(varchar)->đọ dài tối đa 500 ký tự
6,Quản lý đơn hàng->
	-id: int->khóa tự tăng
	-email: string
	-order_date: datetime ->thời điểm dặt đơn hàng
	-Danh sách sản phẩm:
		-sản phẩm 1 x số lượng x giá thời điểm mua
		-sản phẩm 2 x số lượng x giá thời điểm mua

	6.1, Bảng Order
			- id: int tự tăng
			-user_id int
			-order_date: datetime ->thời điểm dặt đơn hàng
			-status: int ->(pending, approved,...)
			-total_money-> tổng tiền đơn hàng
	6.2, Bảng chi tiết đơn hàng
		-id: int tự tăng
		-order_id ->foreign key ->order(id)
		-product_id: int ->foreign key ->product(id)
		-price: int
		-num: int -> sl sản phẩm mua
		-total_money-> lưu tổng tiền của phản phẩm(price * num)



