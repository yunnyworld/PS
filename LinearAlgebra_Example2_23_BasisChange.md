# Example 2.23 (Basis Change) 설명

주어진 선형변환의 행렬이 표준기저( canonical basis )에서

\( A = \begin{pmatrix} 2 & 1 \\ 1 & 2 \end{pmatrix} \)

라고 하자.  
새 기저를

\( B = \left( \begin{pmatrix} 1 \\ 1 \end{pmatrix}, \begin{pmatrix} 1 \\ -1 \end{pmatrix} \right) \)

로 잡는다.

## 1) 기저변환 행렬 \( S \) 만들기

\( S \) 는 “새 기저 \( B \) 의 벡터들을 표준기저 좌표로 세운 행렬”이므로, 열벡터를 그대로 붙이면

\( S = \begin{pmatrix} 1 & 1 \\ 1 & -1 \end{pmatrix} \)

이다.

## 2) 왜 \( S^{-1} = \frac{1}{2}\begin{pmatrix} 1 & 1 \\ 1 & -1 \end{pmatrix} \) 인가?

\( S \) 의 행렬식은

\( \det(S) = (1)(-1) - (1)(1) = -2 \)

이므로 가역이다.  
\( 2 \times 2 \) 역행렬 공식으로

\( S^{-1} = \frac{1}{-2}\begin{pmatrix} -1 & -1 \\ -1 & 1 \end{pmatrix}
= \frac{1}{2}\begin{pmatrix} 1 & 1 \\ 1 & -1 \end{pmatrix} \)

을 얻는다.

## 3) 왜 이 예제에서는 \( \tilde A = S^{-1} A S \) 인가?

일반식은

\( \tilde A = T^{-1} A S \)

이다.

이 예제는 \( A \in \mathbb{R}^{2 \times 2} \) 인 정사각행렬( \( V \to V \) )이고,  
입력공간과 출력공간에 **같은 기저변환**을 적용하므로 \( T = S \) 이다.

따라서

\( \tilde A = S^{-1} A S \)

가 된다. ( similarity transform )

## 4) 실제 계산 결과

\( A = \begin{pmatrix} 2 & 1 \\ 1 & 2 \end{pmatrix} \),  
\( S = \begin{pmatrix} 1 & 1 \\ 1 & -1 \end{pmatrix} \),  
\( S^{-1} = \frac{1}{2}\begin{pmatrix} 1 & 1 \\ 1 & -1 \end{pmatrix} \) 이므로

\( \tilde A = S^{-1} A S = \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix} \)

가 된다.

## 5) 다이어그램 기호 해석 ( \( e, B_0, B, \tilde B, A, \tilde A, S, T \) )

- \( e \), \( B_0 \): 보통 표준기저( canonical basis )를 뜻하는 표기
- \( B \): 기존(또는 old) 기저
- \( \tilde B \): 새 기저
- \( A \): 기존 기저 표현의 선형변환 행렬
- \( \tilde A \): 새 기저 표현의 선형변환 행렬
- \( S \): 입력 쪽 기저변환( \( \tilde B \to B \) )
- \( T \): 출력 쪽 기저변환( \( \tilde C \to C \) ); 이 예제는 같은 공간이라 \( T = S \)

즉, “좌표를 old 기준으로 바꿔서 \( A \) 를 적용한 뒤 다시 new 기준으로 되돌리는” 구조다.

## 6) 직관: 대각화( diagonalization )로 보는 관점

\( \tilde A = \begin{pmatrix} 3 & 0 \\ 0 & 1 \end{pmatrix} \) 이라는 것은,  
기저 \( B \) 에서는 변환이 서로 독립인 두 축 방향으로 각각 \( 3 \), \( 1 \) 배 스케일링만 한다는 뜻이다.

즉 이 예제는 “기저를 잘 고르면 복잡한 행렬이 대각행렬이 된다”는 **기저변환을 통한 대각화**의 전형적인 예시다.
