use std::collections::VecDeque;

fn topological_sort(adj: &[Vec<usize>]) -> Option<Vec<usize>> {
    let n = adj.len();
    let mut indegree = vec![0; n];

    for edges in adj {
        for &v in edges {
            indegree[v] += 1;
        }
    }

    let mut q = VecDeque::new();

    for i in 0..n {
        if indegree[i] == 0 {
            q.push_back(i);
        }
    }

    let mut order = Vec::with_capacity(n);

    while let Some(u) = q.pop_front() {
        order.push(u);

        for &v in &adj[u] {
            indegree[v] -= 1;

            if indegree[v] == 0 {
                q.push_back(v);
            }
        }
    }

    if order.len() == n {
        Some(order)
    } else {
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn is_valid_order(adj: &[Vec<usize>], order: &[usize]) -> bool {
        if order.len() != adj.len() {
            return false;
        }

        let mut pos = vec![0; order.len()];

        for (i, &v) in order.iter().enumerate() {
            pos[v] = i;
        }

        for (u, edges) in adj.iter().enumerate() {
            for &v in edges {
                if pos[u] >= pos[v] {
                    return false;
                }
            }
        }

        true
    }

    #[test]
    fn sorts_a_dag() {
        let adj = vec![vec![1, 2], vec![3], vec![3], vec![4], vec![]];
        let order = topological_sort(&adj).unwrap();

        assert!(is_valid_order(&adj, &order));
        assert_eq!(order, vec![0, 1, 2, 3, 4]);
    }

    #[test]
    fn includes_disconnected_and_isolated_vertices() {
        let adj = vec![vec![1], vec![], vec![3], vec![], vec![]];
        let order = topological_sort(&adj).unwrap();

        assert!(is_valid_order(&adj, &order));
        assert_eq!(order, vec![0, 2, 4, 1, 3]);
    }

    #[test]
    fn handles_duplicate_edges() {
        let adj = vec![vec![1, 1], vec![2], vec![]];
        let order = topological_sort(&adj).unwrap();

        assert_eq!(order, vec![0, 1, 2]);
    }

    #[test]
    fn rejects_a_cycle() {
        let adj = vec![vec![1], vec![2], vec![0]];

        assert_eq!(topological_sort(&adj), None);
    }

    #[test]
    fn rejects_a_self_loop() {
        let adj = vec![vec![0]];

        assert_eq!(topological_sort(&adj), None);
    }

    #[test]
    fn handles_an_empty_graph() {
        let adj: Vec<Vec<usize>> = vec![];

        assert_eq!(topological_sort(&adj), Some(vec![]));
    }
}
