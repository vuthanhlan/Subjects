const VIETNAMESE_ALPHABET =
  "aAáÁạẠàÀảẢãÃăĂắẮặẶằẰẳẲẵẴâÂấẤậẬầẦẩẨẫẪbBcCdDđĐeEéÉẹẸèÈẻẺẽẼêÊếẾệỆềỀểỂễỄgGhHiIíÍịỊìÌỉỈĩĨkKlLmMnNoOóÓọỌòÒỏỎõÕôÔốỐộỘồỒổỔỗỖơƠớỚợỢờỜởỞỡỠpPqQrRsStTuUúÚụỤùÙủỦũŨưƯứỨựỰừỪửỬữỮvVxXyYýÝỵỴỳỲỷỶỹỸ";
const N = VIETNAMESE_ALPHABET.length;
function bin2dec(binary) {
  // number
  let decimal = 0;
  let i = 0;
  while (binary !== 0) {
    const dec = binary % 10;
    decimal += dec * Math.pow(2, i);
    binary = Math.floor(binary / 10);
    i++;
  }
  return decimal; // number
}

function binaryToDecimal(binaryNumber) {
  // string
  let decimalNumber = 0;
  let base = 1; // Base bắt đầu từ 2^0 = 1

  // Lặp qua từng bit của số nhị phân, bắt đầu từ phải sang trái
  for (let i = binaryNumber.length - 1; i >= 0; i--) {
    // Nếu bit là 1, thì cộng vào kết quả
    if (binaryNumber[i] === "1") {
      decimalNumber += base;
    }
    // Di chuyển sang bit tiếp theo bằng cách nhân cơ số lên 2
    base *= 2;
  }

  return decimalNumber; // number
}

function he10sang2(number) {
  // number
  if (number === 0) {
    return "0";
  }

  let binary = "";

  while (number > 0) {
    binary = (number % 2) + binary;
    number = Math.floor(number / 2);
  }

  // return Number(binary);
  return binary; // string
}

//! 6 - Hàm tạo ra 2 số nguyên tố khác nhau có 6 chữ số
const ktraSoNguyenTo = (number) => {
  if (typeof number !== "number" || number !== Math.floor(number)) {
    throw new Error("Tham số đầu vào không hợp lệ");
  }
  for (let i = 2; i <= Math.floor(Math.sqrt(number)); i++) {
    if (number % i === 0) return false;
  }

  return number >= 2;
};

const gcd = (a, b) => {
  if (typeof a !== "number" || typeof b !== "number") {
    throw new Error("Tham số phải là số");
  }
  if (b === 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
};

const kiemTra2soNTCungNhau = (a, b) => {
  return gcd(a, b) === 1;
};

const sinhSoNguyenToNgauNhien = () => {
  let min = 1000;
  let max = 9999;
  let randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;
  while (!ktraSoNguyenTo(randomNumber)) {
    randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;
  }
  return randomNumber; // number
};

const sinhSoNgauNhien = () => {
  let min = 2;
  let max = 99;
  let randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;

  return randomNumber; // number
};

//! 3 - Hàm tính a mũ -1 mod b (Tìm phần tử nghịch đảo)
const phanTuNghichDao = (a, b) => {
  if (
    typeof a !== "number" ||
    typeof b !== "number" ||
    !kiemTra2soNTCungNhau(a, b)
  ) {
    throw new Error(
      "Tham số đầu vào không hợp lệ, không thể tìm phần tử nghịch đảo"
    );
  }

  let r_i_tru_2 = b;
  let r_i_tru_1 = a;

  let x_i_tru_2 = 0;
  let x_i_tru_1 = 1;

  for (let i = 1; r_i_tru_1 !== 1; i++) {
    let q = Math.floor(r_i_tru_2 / r_i_tru_1);
    // console.log("r_i_tru_2 | r_i_tru_1 :: ", r_i_tru_2, r_i_tru_1);

    let tmp_r = r_i_tru_1;
    r_i_tru_1 = r_i_tru_2 - q * r_i_tru_1;
    r_i_tru_2 = tmp_r;

    let tmp_x = x_i_tru_1;
    x_i_tru_1 = x_i_tru_2 - q * x_i_tru_1;
    x_i_tru_2 = tmp_x;
  }

  while (x_i_tru_1 < 0) {
    x_i_tru_1 += b;
  }

  return x_i_tru_1;
};

const a_mu_b_mod_n = (a, b, n) => {
  if (typeof a !== "number" || typeof b !== "number" || typeof n !== "number") {
    throw new Error("Tham số đầu vào không hợp lệ");
  }
  // console.log(`${a}^${b} mod ${n} = `);

  if (b === n) {
    return a % n;
  }

  const binaryArray = he10sang2(b).split("");

  let f = 1;
  for (let i = 0; i < binaryArray.length; i++) {
    f = (f * f) % n;

    if (binaryArray[i] === "1") {
      f = (f * a) % n;
    }
  }

  return f; // number
};

const p = sinhSoNguyenToNgauNhien();
const q = sinhSoNguyenToNgauNhien();

console.log("{p,q} = ", { p, q });

const n = p * q;

const phi = (p - 1) * (q - 1);

let e = sinhSoNguyenToNgauNhien();

while (!kiemTra2soNTCungNhau(e, phi)) e = sinhSoNguyenToNgauNhien();

console.log("\ne = ", e);

const d = phanTuNghichDao(e, phi);

console.log("\nPublic key: ", { n, e });
console.log("Private key: ", { n, d });

const VIETNAMESE_ALPHABET_FOR_RSA = VIETNAMESE_ALPHABET + "_"; // 179

const maHoaRSA = (plaintext, isBin = false) => {
  if (typeof plaintext === "string") {
    plaintext = plaintext.trim().replaceAll(" ", "_");

    let c_text = "";

    for (let i = 0; i < plaintext.length; i++) {
      const index = VIETNAMESE_ALPHABET_FOR_RSA.indexOf(plaintext[i]);
      if (index === -1) {
        throw new Error("Tham số đầu vào chứa kí tự không hợp lệ");
      } else {
        c_text += a_mu_b_mod_n(index, e, n) + "-";
      }
    }
    return c_text;
  }

  if (isBin) {
    plaintext = bin2dec(plaintext); // 10
    return he10sang2(a_mu_b_mod_n(plaintext, e, n)); // c
  }

  return a_mu_b_mod_n(plaintext, e, n); // c
};

const giaiMaRSA = (ciphertext, isBin = false) => {
  if (typeof ciphertext === "string" && isBin === false) {
    let plaintext = "";
    ciphertext = ciphertext.trim().split("-");

    for (let i = 0; i < ciphertext.length - 1; i++) {
      let index = a_mu_b_mod_n(Number(ciphertext[i]), d, n);
      plaintext += VIETNAMESE_ALPHABET_FOR_RSA[index];
    }
    return plaintext.replaceAll("_", " ");
  }

  if (isBin) {
    ciphertext = binaryToDecimal(ciphertext);
    return he10sang2(a_mu_b_mod_n(ciphertext, d, n)); // m
  }
  return a_mu_b_mod_n(ciphertext, d, n); // m
};

// TH 1: m = 32
console.log("\n=== TH 1 ==");

const m = 10;
console.log("m input :: ", m);

const C = maHoaRSA(m);
console.log("C :: ", C);

const M = giaiMaRSA(C);
console.log("M :: ", M);

// TH 2: m = 1010
console.log("\n=== TH 2 ==");

const maNhiPhan = 1010;
console.log("\nmaNhiPhan input :: ", maNhiPhan);

const C_maNhiPhan = maHoaRSA(maNhiPhan, true);
console.log("C_maNhiPhan :: ", C_maNhiPhan);

const M_maNhiPhan = giaiMaRSA(C_maNhiPhan, true);
console.log("M_maNhiPhan :: ", M_maNhiPhan);

// TH 3:
console.log("\n=== TH 3 ==");
const input = "Dương Văn Dũng";
console.log("input :>> ", input);

const C_2 = maHoaRSA(input);
console.log("C :: ", C_2);

const M_2 = giaiMaRSA(C_2);
console.log("M :: ", M_2);
